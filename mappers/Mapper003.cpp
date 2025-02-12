
#include "Mapper003.h"
#include "Cart.h"
#include "NES.h"
#include <cassert>

SETUP_STATIC_INES_MAPPER_REGISTRAR(3)

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Mapper3::Mapper3() {

	set_prg_89ab(0);
	set_prg_cdef(-1);

	set_chr_0000_1fff(0);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
std::string Mapper3::name() const {
	return "CNROM";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_8(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_9(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_a(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_b(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_c(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_d(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_e(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper3::write_f(uint16_t address, uint8_t value) {
	(void)address;
	set_chr_0000_1fff(value);
}
