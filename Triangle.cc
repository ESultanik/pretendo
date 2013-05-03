
#include "Triangle.h"
#include <cstdio>

namespace {

const uint8_t sequence[32] = {
   0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08,
   0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
   0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Triangle::Triangle() : enabled_(false), timer_load_(0), sequence_index_(0) {

}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
Triangle::~Triangle() {

}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Triangle::enable() {
	enabled_ = true;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void Triangle::disable() {
	enabled_ = false;
	length_counter_.clear();
}

//------------------------------------------------------------------------------
// Name: write_reg0
//------------------------------------------------------------------------------
void Triangle::write_reg0(uint8_t value) {

	if(value & 0x80) {
		length_counter_.halt();
	} else {
		length_counter_.resume();
	}
	
	linear_counter_.set_mode(value & 0x80);
	linear_counter_.set_reload(value & 0x7f);
}

//------------------------------------------------------------------------------
// Name: write_reg2
//------------------------------------------------------------------------------
void Triangle::write_reg2(uint8_t value) {
	timer_load_ = (timer_load_  & 0xff00) | value;
	timer_.set_frequency(timer_load_ + 1);	
}

//------------------------------------------------------------------------------
// Name: write_reg3
//------------------------------------------------------------------------------
void Triangle::write_reg3(uint8_t value) {

	if(enabled_) {
		length_counter_.load((value >> 3) & 0x1f);
	}

	timer_load_ = (timer_load_ & 0x00ff) | ((value & 0x07) << 8);
	timer_.set_frequency(timer_load_ + 1);
	
	linear_counter_.halt();
}

//------------------------------------------------------------------------------
// Name: enabled
//------------------------------------------------------------------------------
bool Triangle::enabled() const {
	return enabled_;
}

//------------------------------------------------------------------------------
// Name: length_counter
//------------------------------------------------------------------------------
LengthCounter &Triangle::length_counter() {
	return length_counter_;
}

//------------------------------------------------------------------------------
// Name: linear_counter
//------------------------------------------------------------------------------
LinearCounter &Triangle::linear_counter() {
	return linear_counter_;
}

//------------------------------------------------------------------------------
// Name: tick
//------------------------------------------------------------------------------
void Triangle::tick() {
	if(timer_.tick()) {
		sequence_index_ = (sequence_index_ + 1) % 32;
	}
}

//------------------------------------------------------------------------------
// Name: dac
//------------------------------------------------------------------------------
uint8_t Triangle::output() const {
	if(length_counter_.value() && linear_counter_.value()) {
		if(timer_.frequency() < 4) {
			return 0x00;
		} else {
			return sequence[sequence_index_];
		}
	}
}
