/**
 * @file CityDelayedEvent.hpp
 * @brief CityDelayedEvent class - Delay a node for a time window
 * 
 * @details
 * This event applies a delay to a target node and reverts it when the
 * event duration ends. It is used by the event system to model city delays.
 * 
 * @note
 * principles SRP, Polymorphism
 */

#pragma once

#include "Forward.hpp"

#include "Event.hpp"
#include "Node.hpp"

class CityDelayedEvent : public AEvent {
private:
	Node* _target;
	Time _delay;

public:
	CityDelayedEvent(Time p_duration, Node* p_target, Time p_delay);
	~CityDelayedEvent();

	void apply();
	void revert();
	void printEvent() const;
};

