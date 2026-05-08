#include "Rail.hpp"

Rail::Rail(Node* p_departure, Node* p_arrival, double p_lenght, double p_speed) : _prevNode(p_departure),
	_nextNode(p_arrival), _lenght(p_lenght * 1000), _speedMax(p_speed / 3.6), _blocked(false), _limitationSpeed(p_speed / 3.6) {
	std::cout << "[Rail] " << p_departure->getName() << " <--> " << p_arrival->getName() << ", size:" << p_lenght << " km, speed:" << p_speed << " km/h, created"  << std::endl;
}

Rail::~Rail() {
}

double Rail::getSpeedMax() const {
	return _limitationSpeed < _speedMax ? _limitationSpeed : _speedMax;
}

std::ostream& operator<<(std::ostream& os, const Rail& rail) {
	os << "[RAIL] prevNode=";

	if (rail.getPrevNode()) {
		os << rail.getPrevNode()->getName();
	}
	else {
		os << "null";
	}

	os << ", nextNode=";

	if (rail.getNextNode()) {
		os << rail.getNextNode()->getName();
	}
	else {
		os << "null";
	}

	os << ", lenght=" << rail.getLenght() / 1000 << "km, speedMax=" << rail.getSpeedMax() * 3.6 << "km/h";
	return os;
}
