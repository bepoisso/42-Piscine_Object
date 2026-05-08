#include "CityDelayedEvent.hpp"


CityDelayedEvent::CityDelayedEvent(Time p_duration, Node* p_target, Time p_delay) : AEvent(p_duration), _target(p_target), _delay(p_delay) {
}

CityDelayedEvent::~CityDelayedEvent() {
}

void CityDelayedEvent::apply() {
	_target->setDelay(_delay);

}

void CityDelayedEvent::revert() {
	_target->setDelay(0);
}

void CityDelayedEvent::printEvent() const {
	std::cout << "[EVENT] new event created: City Delayed (";
	std::cout << _target->getName() << " delayed for " << _delay;
	std::cout << ") duration of event " << _duration << std::endl;
}

