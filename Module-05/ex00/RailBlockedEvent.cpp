#include "RailBlockedEvent.hpp"

RailBlockedEvent::RailBlockedEvent(Time p_duration, Rail* p_target) : AEvent(p_duration), _target(p_target) {
}

RailBlockedEvent::~RailBlockedEvent() {
}

void RailBlockedEvent::apply() {
	_target->setBlocked(true);
}

void RailBlockedEvent::revert() {
	_target->setBlocked(false);
}

void RailBlockedEvent::printEvent() const {
	std::cout << "[EVENT] new event created: Rail Blocked (";
	std::cout << _target->getPrevNode()->getName() << " <---> " << _target->getNextNode()->getName();
	std::cout << ") duration of event " << _duration << std::endl;
}


