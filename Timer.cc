
#include "Timer.h"

//------------------------------------------------------------------------------
// Name: Timer
//------------------------------------------------------------------------------
Timer::Timer() : timer_(0xffff), frequency_(0xffff) {

}

//------------------------------------------------------------------------------
// Name: tick
//------------------------------------------------------------------------------
bool Timer::tick() {
	if(--timer_ == 0) {
		timer_ = frequency_;
		return true;
	}
	
	return false;
}

//------------------------------------------------------------------------------
// Name: set_frequency
//------------------------------------------------------------------------------
void Timer::set_frequency(uint16_t frequency) {
	frequency_ = frequency;
	timer_     = frequency_;
}

//------------------------------------------------------------------------------
// Name: reset
//------------------------------------------------------------------------------
void Timer::reset() {
	timer_ = frequency_;
}

//------------------------------------------------------------------------------
// Name: frequency
//------------------------------------------------------------------------------
uint16_t Timer::frequency() const {
	return frequency_;
}