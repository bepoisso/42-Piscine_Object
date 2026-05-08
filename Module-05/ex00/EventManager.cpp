#include "EventManager.hpp"


EventManager::EventManager(SimulationEngine* p_sim) : _mediator(p_sim) {
}

EventManager::~EventManager() {
	for (std::vector<AEvent*>::iterator it = _events.begin(); it != _events.end(); ++it)
		delete *it;
	_events.clear();
}

void EventManager::update(long int p_dt) {
	for (std::vector<AEvent*>::iterator it = _events.begin(); it != _events.end();) {
		(*it)->update(p_dt);
		if ((*it)->isFinished()) {
			delete *it;
			it = _events.erase(it);
		}
		else
			++it;
	}
}

void EventManager::generateRandomEvent() {
	int r = std::rand() % 3;
	Time duration(std::rand() % 2401 + 1200);

	switch (r) {
		case CITY_DELAYED: {
			Node* city = _mediator->getRandCity();
			Time delay(std::rand() % 1501 + 300);
			_events.push_back(new CityDelayedEvent(duration, city, delay));
			break;
		}
		case RAIL_LIMITATION: {
			Rail* rail = _mediator->getRandRail();
			double speed = static_cast<double>(std::rand() % 71 + 50) / 3.6;
			_events.push_back(new RailLimitationEvent(duration, rail, speed));
			break;
		}
		case RAIL_BLOCKED: {
			Rail* rail = _mediator->getRandRail();
			_events.push_back(new RailBlockedEvent(duration, rail));
			break;
		}
	}
	_events.back()->printEvent();
}



