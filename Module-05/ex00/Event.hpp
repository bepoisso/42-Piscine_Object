/**
 * @file Event.hpp
 * @brief AEvent class - Base class for simulation events
 * 
 * @details
 * Defines the event lifecycle (update, apply, revert) and state flags that
 * manage event duration and completion.
 * 
 * @note
 * principles Abstraction, Polymorphism
 */

#pragma once

#include <string>

#include "Forward.hpp"

#include "Time.hpp"

class AEvent {
protected:
	Time _duration;
	Time _elapsed;
	bool _active;
	bool _finished;

public:
	AEvent(Time p_duration);
	virtual ~AEvent() {}

	virtual void update(long int dt);
	virtual bool isFinished() const;

	virtual void revert() = 0;
	virtual void apply() = 0;
	virtual void printEvent() const = 0;
};

