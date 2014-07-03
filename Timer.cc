
#include "Timer.h"

//------------------------------------------------------------------------------
// Name: Timer
//------------------------------------------------------------------------------
Timer::Timer() : frequency(0xffff), timer_(0xffff) {

}

//------------------------------------------------------------------------------
// Name: tick
//------------------------------------------------------------------------------
bool Timer::tick() {
	if(--timer_ == 0) {
		timer_ = frequency;
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------
// Name: reset
//------------------------------------------------------------------------------
void Timer::reset() {
	timer_ = frequency;
}

//------------------------------------------------------------------------------
// Name: value
//------------------------------------------------------------------------------
uint16_t Timer::value() const {
	return timer_;
}
