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

