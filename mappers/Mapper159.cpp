
#include "Mapper159.h"
#include "Bandai.h"

SETUP_STATIC_INES_MAPPER_REGISTRAR(159)

//------------------------------------------------------------------------------
// Name: Mapper159
//------------------------------------------------------------------------------
Mapper159::Mapper159() : mapper_(new Bandai) {
}

//------------------------------------------------------------------------------
// Name: name
//------------------------------------------------------------------------------
std::string Mapper159::name() const {
	return "Bandai FCG";
}

//------------------------------------------------------------------------------
// Name: read_6
//------------------------------------------------------------------------------
uint8_t Mapper159::read_6(uint16_t address) {
	return mapper_->read_6(address);
}

//------------------------------------------------------------------------------
// Name: read_7
//------------------------------------------------------------------------------
uint8_t Mapper159::read_7(uint16_t address) {
	return mapper_->read_7(address);
}

//------------------------------------------------------------------------------
// Name: write_6
//------------------------------------------------------------------------------
void Mapper159::write_6(uint16_t address, uint8_t value) {
	return mapper_->write_6(address, value);
}

//------------------------------------------------------------------------------
// Name: write_7
//------------------------------------------------------------------------------
void Mapper159::write_7(uint16_t address, uint8_t value) {
	return mapper_->write_7(address, value);
}

//------------------------------------------------------------------------------
// Name: write_8
//------------------------------------------------------------------------------
void Mapper159::write_8(uint16_t address, uint8_t value) {
	return mapper_->write_8(address, value);
}

//------------------------------------------------------------------------------
// Name: write_9
//------------------------------------------------------------------------------
void Mapper159::write_9(uint16_t address, uint8_t value) {
	return mapper_->write_9(address, value);
}

//------------------------------------------------------------------------------
// Name: write_a
//------------------------------------------------------------------------------
void Mapper159::write_a(uint16_t address, uint8_t value) {
	return mapper_->write_a(address, value);
}

//------------------------------------------------------------------------------
// Name: write_b
//------------------------------------------------------------------------------
void Mapper159::write_b(uint16_t address, uint8_t value) {
	return mapper_->write_b(address, value);
}

//------------------------------------------------------------------------------
// Name: write_c
//------------------------------------------------------------------------------
void Mapper159::write_c(uint16_t address, uint8_t value) {
	return mapper_->write_c(address, value);
}

//------------------------------------------------------------------------------
// Name: write_d
//------------------------------------------------------------------------------
void Mapper159::write_d(uint16_t address, uint8_t value) {
	return mapper_->write_d(address, value);
}

//------------------------------------------------------------------------------
// Name: write_e
//------------------------------------------------------------------------------
void Mapper159::write_e(uint16_t address, uint8_t value) {
	return mapper_->write_e(address, value);
}

//------------------------------------------------------------------------------
// Name: write_f
//------------------------------------------------------------------------------
void Mapper159::write_f(uint16_t address, uint8_t value) {
	return mapper_->write_f(address, value);
}

//------------------------------------------------------------------------------
// Name: cpu_sync
//------------------------------------------------------------------------------
void Mapper159::cpu_sync() {
	return mapper_->cpu_sync();
}
