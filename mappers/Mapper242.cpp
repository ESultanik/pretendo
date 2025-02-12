
#include "Mapper242.h"
#include "PPU.h"
#include "NES.h"
#include "Cart.h"
#include <cstring>

SETUP_STATIC_INES_MAPPER_REGISTRAR(242)

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Mapper242::Mapper242() {
	write_handler(0, 0);

	memset(chr_ram_, 0, sizeof(chr_ram_));

	if(nes::cart.has_chr_rom()) {
		set_chr_0000_1fff(0);
	} else {
		set_chr_0000_1fff_ram(chr_ram_, 0);
	}
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
std::string Mapper242::name() const {
	return "iNES 242";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_8(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_9(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_a(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_b(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_c(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_d(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_e(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_f(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper242::write_handler(uint16_t address, uint8_t value) {
	(void)value;

	set_prg_89abcdef((address >> 3) & 0x0f);

	if(address & 0x02) {
		nes::ppu::set_mirroring(nes::ppu::mirror_horizontal);
	} else {
		nes::ppu::set_mirroring(nes::ppu::mirror_vertical);
	}
}
