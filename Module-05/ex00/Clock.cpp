#include "Clock.hpp"

AClock::AClock() {
}

AClock::AClock(long int p_startTime) : _currentTime(Time(p_startTime)) {
}

AClock::~AClock() {
}

void AClock::add(long int p_dt) {
	_currentTime = _currentTime + p_dt;
}

void AClock::init(long int p_st) {
	_currentTime = Time(p_st);
}
