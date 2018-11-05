
#include "DMC.h"
#include "APU.h"
#include "CPU.h"
#include "Mapper.h"

namespace nes {
namespace apu {
namespace {

// NTSC period table
const uint16_t frequency_table[16] = {
	0x1ac, 0x17c, 0x154, 0x140,
	0x11e, 0x0fe, 0x0e2, 0x0d6,
	0x0be, 0x0a0, 0x08e, 0x080,
	0x06a, 0x054, 0x048, 0x036
};

}

/* NOTE:
 * The following is speculation, and thus not necessarily 100% accurate. It does accurately predict observed behavior.
 * The 6502 cannot be pulled off of the bus normally. The 2A03 DMC gets around this by pulling RDY low internally.
 * This causes the CPU to pause during the next read cycle, until RDY goes high again. The DMC unit holds RDY low for 4 cycles.
 * The first three cycles it idles, as the CPU could have just started an interrupt cycle, and thus be writing for 3 consecutive cycles (and thus ignoring RDY).
 * On the fourth cycle, the DMC unit drives the next sample address onto the address lines, and reads that byte from memory.
 * It then drives RDY high again, and the CPU picks up where it left off.
 * This matters because on NTSC NES and Famicom, it can interfere with the expected operation of any register where reads have a side effect:
 * the controller registers ($4016 and $4017), reads of the PPU status register ($2002), and reads of VRAM/VROM data ($2007) if they happen to occur in the same cycle that the DMC unit pulls RDY low.
 * For the controller registers, this can cause an extra rising clock edge to occur, and thus shift an extra bit out.
 * For the others, the PPU will see multiple reads, which will cause extra increments of the address latches, or clear the vblank flag.
 * This problem has been fixed on the 2A07 and PAL NES is exempt of this bug.
 */

// TODO(eteran): make the output clocking match http://wiki.nesdev.com/w/index.php/APU_DMC
// we are close, but the sample_buffer stuff is confusingly worded there...

//------------------------------------------------------------------------------
// Name: load_sample_buffer
//------------------------------------------------------------------------------
void DMC::load_sample_buffer(uint8_t value) {
	shift_register_.load(value);
}

//------------------------------------------------------------------------------
// Name: set_enabled
//------------------------------------------------------------------------------
void DMC::set_enabled(bool value) {
	if(value) {
		enable();
	} else {
		disable();
	}
}

//------------------------------------------------------------------------------
// Name: enable
//------------------------------------------------------------------------------
void DMC::enable() {

	if(bytes_remaining_ == 0) {
		bytes_remaining_ = sample_length_;
	}

	if(output_clock()) {
		start_cycle();
	}
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void DMC::disable() {
	bytes_remaining_ = 0;
}

//------------------------------------------------------------------------------
// Name: write_reg0
//------------------------------------------------------------------------------
void DMC::write_reg0(uint8_t value) {

	control_.value = value;

	timer_.frequency = frequency_table[control_.frequency];
	timer_.reset();

	if(!irq_enabled()) {
		nes::apu::status.dmc_irq = false;
		if(!nes::apu::status.irq_firing) {
			nes::cpu::clear_irq(nes::cpu::APU_IRQ);
		}
	}
}

//------------------------------------------------------------------------------
// Name: write_reg1
//------------------------------------------------------------------------------
void DMC::write_reg1(uint8_t value) {
	output_ = value & 0x7f;
}

//------------------------------------------------------------------------------
// Name: write_reg2
//------------------------------------------------------------------------------
void DMC::write_reg2(uint8_t value) {
	sample_address_ = 0xc000 | (value << 6);
	sample_pointer_ = sample_address_;
}

//------------------------------------------------------------------------------
// Name: write_reg3
//------------------------------------------------------------------------------
void DMC::write_reg3(uint8_t value) {
	sample_length_ = (value << 4) | 1;
	if(bytes_remaining_ == 0) {
		bytes_remaining_ = sample_length_;
	}
}

//------------------------------------------------------------------------------
// Name: bytes_remaining
//------------------------------------------------------------------------------
uint16_t DMC::bytes_remaining() const {
	return bytes_remaining_;
}


//------------------------------------------------------------------------------
// Name: output_clock
//------------------------------------------------------------------------------
bool DMC::output_clock() {
	if(bits_remaining_ != 0) {

		// 1. If the silence flag is clear, the output level changes based on bit 0 of the shift register.
		// If the bit is 1, add 2; otherwise, subtract 2.
		// But if adding or subtracting 2 would cause the output level to leave the 0-127 range, leave the output level unchanged.
		// This means subtract 2 only if the current level is at least 2, or add 2 only if the current level is at most 125.
		if(!muted_) {
			if(shift_register_.value()) {
				if(output_ <= 0x7d) {
					output_ += 2;
				}
			} else {
				if(output_ >= 0x02) {
					output_ -= 2;
				}
			}
		}

		// 2. The right shift register is clocked.
		shift_register_.clock();

		// 3. the bits-remaining counter is decremented. If it becomes zero, a new output cycle is started.
		--bits_remaining_;
		return bits_remaining_ == 0;
	}

	return true;
}

//------------------------------------------------------------------------------
// Name: start_cycle
//------------------------------------------------------------------------------
void DMC::start_cycle() {
	// immediate load the first byte if the shift counter is empty
	if(bytes_remaining_ != 0) {

		// 1. The bits-remaining counter is loaded with 8.
		bits_remaining_ = 8;

		nes::cpu::schedule_dmc_dma([](uint8_t value){
			nes::apu::dmc.load_sample_buffer(value);
		}, sample_pointer_, 1);

		sample_pointer_ = ((sample_pointer_ + 1) & 0xffff) | 0x8000;

		// last byte of the sample?
		if(--bytes_remaining_ == 0) {
			if(loop()) {
				bytes_remaining_ = sample_length_;
				sample_pointer_  = sample_address_;
			} else if(irq_enabled()) {
				nes::cpu::irq(nes::cpu::APU_IRQ);
				nes::apu::status.dmc_irq = true;
			}
		}
	}
}

//------------------------------------------------------------------------------
// Name: tick
//------------------------------------------------------------------------------
void DMC::tick() {

	timer_.tick([this]() {
		if(output_clock()) {
			start_cycle();
		}
	});
}

//------------------------------------------------------------------------------
// Name: output
//------------------------------------------------------------------------------
uint8_t DMC::output() const {
	return output_ & 0x7f;
}

//------------------------------------------------------------------------------
// Name: irq_enabled
//------------------------------------------------------------------------------
bool DMC::irq_enabled() const {
	return control_.irq;
}

//------------------------------------------------------------------------------
// Name: loop
//------------------------------------------------------------------------------
bool DMC::loop() const {
	return control_.loop;
}

}
}
