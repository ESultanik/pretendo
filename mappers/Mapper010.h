
#ifndef MAPPER0_10_20080314_H_
#define MAPPER0_10_20080314_H_

#include "Mapper.h"

class Mapper10 : public Mapper {
public:
	Mapper10();

public:
	virtual std::string name() const;

public:
	virtual void write_a(uint16_t address, uint8_t value);
	virtual void write_b(uint16_t address, uint8_t value);
	virtual void write_c(uint16_t address, uint8_t value);
	virtual void write_d(uint16_t address, uint8_t value);
	virtual void write_e(uint16_t address, uint8_t value);
	virtual void write_f(uint16_t address, uint8_t value);

public:
	virtual uint8_t read_vram(uint16_t address);

private:
	bool    latch1_;
	bool    latch2_;
	uint8_t latch1_lo_;
	uint8_t latch1_hi_;
	uint8_t latch2_lo_;
	uint8_t latch2_hi_;
};

#endif