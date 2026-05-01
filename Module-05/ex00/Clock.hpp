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
