
#include "Mapper024.h"
#include "VRC6.h"
#include <cstring>

SETUP_STATIC_INES_MAPPER_REGISTRAR(24)

//------------------------------------------------------------------------------
// Name: Mapper24
//------------------------------------------------------------------------------
Mapper24::Mapper24() : mapper_(new VRC6) {
}

//------------------------------------------------------------------------------
// Name: name
//------------------------------------------------------------------------------
std::string Mapper24::name() const {
	return "VRC6a";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_8(uint16_t address, uint8_t value) {
	mapper_->write_8(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_9(uint16_t address, uint8_t value) {
	mapper_->write_9(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_a(uint16_t address, uint8_t value) {
	mapper_->write_a(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_b(uint16_t address, uint8_t value) {
	mapper_->write_b(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_c(uint16_t address, uint8_t value) {
	mapper_->write_c(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_d(uint16_t address, uint8_t value) {
	mapper_->write_d(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_e(uint16_t address, uint8_t value) {
	mapper_->write_e(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::write_f(uint16_t address, uint8_t value) {
	mapper_->write_f(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper24::cpu_sync() {
	mapper_->cpu_sync();
}
