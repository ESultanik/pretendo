
#include "Mapper201.h"

SETUP_STATIC_INES_MAPPER_REGISTRAR(201)

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Mapper201::Mapper201() {

	set_prg_89ab(0);
	set_prg_cdef(-1);
	set_chr_0000_1fff(0);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
std::string Mapper201::name() const {
	return "iNES 201";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_8(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_9(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_a(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_b(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_c(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_d(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_e(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_f(uint16_t address, uint8_t value) {
	write_handler(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper201::write_handler(uint16_t address, uint8_t value) {
	(void)value;

	set_prg_89abcdef(address & 0x00ff);
	set_chr_0000_1fff(address & 0x00ff);
}
