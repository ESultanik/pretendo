
#include "Mapper226.h"
#include "PPU.h"
#include <cstring>

SETUP_STATIC_INES_MAPPER_REGISTRAR(226)

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Mapper226::Mapper226() {
	memset(chr_ram_, 0, sizeof(chr_ram_));

	regs_[0] = 0;
	regs_[1] = 0;

	writer_handler(0x8000, 0);
	writer_handler(0x8001, 0);

	set_chr_0000_1fff_ram(chr_ram_, 0);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
std::string Mapper226::name() const {
	return "76-in-1";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_8(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_9(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_a(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_b(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_c(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_d(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_e(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::write_f(uint16_t address, uint8_t value) {
	writer_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper226::writer_handler(uint16_t address, uint8_t value) {

	regs_[address & 0x0001] = value;

	if(regs_[0] & 0x40) {
		nes::ppu::set_mirroring(nes::ppu::mirror_horizontal);
	} else {
		nes::ppu::set_mirroring(nes::ppu::mirror_vertical);
	}

	uint32_t prg_page = ((regs_[0] >> 1) & 0x0f) | ((regs_[0] >> 3) & 0x10) | ((regs_[1] & 0x01) << 5);

	if(regs_[0] & 0x20) {
		// 16k mode
		prg_page *= 2;
		if(regs_[0] & 0x01) {
			prg_page += 1;
		}
		set_prg_89ab(prg_page);
		set_prg_cdef(prg_page);
	} else {
		// 32k mode
		set_prg_89abcdef(prg_page);
	}
}
