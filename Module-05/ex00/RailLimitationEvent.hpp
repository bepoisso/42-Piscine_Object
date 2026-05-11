/**
 * @file RailLimitationEvent.hpp
 * @brief RailLimitationEvent class - Limit rail speed
 * 
 * @details
 * Event that applies a temporary speed limitation to a rail and can revert
 * it when the event ends.
 * 
 * @note
 * principles SRP, Polymorphism
 */

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

