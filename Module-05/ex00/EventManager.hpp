#pragma once

#include <vector>

#include "Forward.hpp"

#include "SimulationEngine.hpp"
#include "Event.hpp"
#include "CityDelayedEvent.hpp"
#include "RailLimitationEvent.hpp"
#include "RailBlockedEvent.hpp"


class EventManager {
private:
	SimulationEngine* _mediator;
	std::vector<AEvent*> _events;	// owning: EventManager own and manage Event

public:
	EventManager(SimulationEngine* p_sim);
	~EventManager();

	void update(long int dt);
	void generateRandomEvent();
};
