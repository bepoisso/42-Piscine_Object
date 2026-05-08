#pragma once

#include "Forward.hpp"
#include "Event.hpp"
#include "Rail.hpp"

class RailLimitationEvent : public AEvent {
private:
	Rail* _target;
	double _limitation;

public:
	RailLimitationEvent(Time p_duration, Rail* p_target, double p_limitation);
	~RailLimitationEvent();

	void apply();
	void revert();
	void printEvent() const;
};

