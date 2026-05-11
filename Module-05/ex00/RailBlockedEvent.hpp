/**
 * @file RailBlockedEvent.hpp
 * @brief RailBlockedEvent class - Block a rail segment
 * 
 * @details
 * Event that marks a rail as blocked for a duration and can revert it
 * when the event ends.
 * 
 * @note
 * principles SRP, Polymorphism
 */

#pragma once

#include "Forward.hpp"
#include "Event.hpp"
#include "Rail.hpp"

class RailBlockedEvent : public AEvent {
private:
	Rail* _target;

public:
	RailBlockedEvent(Time p_duration, Rail* p_target);
	~RailBlockedEvent();

	void apply();
	void revert();
	void printEvent() const;
};
