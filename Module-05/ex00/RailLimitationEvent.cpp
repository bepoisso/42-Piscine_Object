#include "RailLimitationEvent.hpp"

RailLimitationEvent::RailLimitationEvent(Time p_duration, Rail* p_target, double p_limitation) : AEvent(p_duration), _target(p_target), _limitation(p_limitation) {
}

RailLimitationEvent::~RailLimitationEvent() {
}

void RailLimitationEvent::apply() {
	_target->setLimitationSpeed(_limitation);
}

void RailLimitationEvent::revert() {
	_target->setLimitationSpeed(_target->getSpeedMax());
}

void RailLimitationEvent::printEvent() const {
	std::cout << "[EVENT] new event created: Rail Limitation (";
	std::cout << _target->getPrevNode()->getName() << " <---> " << _target->getNextNode()->getName();
	std::cout << "  limited at " << _limitation * 3.6 << "km/h) duration of event " << _duration << std::endl;
}

