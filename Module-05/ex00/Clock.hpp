/**
 * @file Clock.hpp
 * @brief AClock class - Abstract timekeeper
 * 
 * @details
 * Defines the base interface for time management and exposes current time
 * handling shared by clocks. Concrete clocks implement the update logic.
 * 
 * @note
 * principles Abstraction, SRP
 */

#pragma once

#include "Forward.hpp"

#include "Time.hpp"

class AClock {
private:
	Time _currentTime;
public:
	AClock();
	AClock(long int p_startTime);
	virtual ~AClock();

	void add(long int p_dt);
	virtual void update(long int p_dt) = 0;
	virtual void init(long int p_st);
	Time getCurrentTime() { return _currentTime; }
};
