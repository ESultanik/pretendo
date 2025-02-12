
#include "Mapper002.h"
#include "Cart.h"
#include <cstring>

SETUP_STATIC_INES_MAPPER_REGISTRAR(2)

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Mapper2::Mapper2() {
	memset(chr_ram_, 0, sizeof(chr_ram_));

	set_prg_89ab(0);
	set_prg_cdef(-1);
	set_chr_0000_1fff_ram(chr_ram_, 0);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
std::string Mapper2::name() const {
	return "UxROM";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_8(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_9(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_a(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_b(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_c(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_d(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_e(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper2::write_f(uint16_t address, uint8_t value) {
	(void)address;
	set_prg_89ab(value);
}
