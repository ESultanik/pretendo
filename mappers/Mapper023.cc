
#include "Mapper023.h"
#include "VRC2.h"
#include <cstring>

SETUP_STATIC_INES_MAPPER_REGISTRAR(23)

//------------------------------------------------------------------------------
// Name: Mapper23
//------------------------------------------------------------------------------
Mapper23::Mapper23() : mapper_(new VRC2(0)) {

}

//------------------------------------------------------------------------------
// Name: ~Mapper23
//------------------------------------------------------------------------------
Mapper23::~Mapper23() {
	delete mapper_;
}

//------------------------------------------------------------------------------
// Name: name
//------------------------------------------------------------------------------
std::string Mapper23::name() const {
	return "VRC2b";
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
uint8_t Mapper23::read_6(uint16_t address) {
	return mapper_->read_6(address);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_6(uint16_t address, uint8_t value) {
	mapper_->write_6(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_8(uint16_t address, uint8_t value) {
	mapper_->write_8(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_9(uint16_t address, uint8_t value) {
	mapper_->write_9(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_a(uint16_t address, uint8_t value) {
	mapper_->write_a(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_b(uint16_t address, uint8_t value) {
	mapper_->write_b(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_c(uint16_t address, uint8_t value) {
	mapper_->write_c(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_d(uint16_t address, uint8_t value) {
	mapper_->write_d(address, value);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Mapper23::write_e(uint16_t address, uint8_t value) {
	mapper_->write_e(address, value);
}
