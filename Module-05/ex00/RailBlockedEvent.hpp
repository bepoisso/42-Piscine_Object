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
