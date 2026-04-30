#include "Rail.hpp"

Rail::Rail(Node* p_departure, Node* p_arrival, float p_lenght, float p_speed) : _prevNode(p_departure), _nextNode(p_arrival), _lenght(p_lenght), _speedMax(p_speed) {
	std::cout << "[Rail] " << p_departure->getName() << " <--> " << p_arrival->getName() << ", size:" << p_lenght << " km, speed:" << p_speed << " km/h, created"  << std::endl;
}

Rail::~Rail() {
}

std::ostream& operator<<(std::ostream& os, const Rail& rail) {
	os << "[RAIL] prevNode=";
	if (rail.getprevNode()) {
		os << rail.getprevNode()->getName();
	} else {
		os << "null";
	}
	os << ", nextNode=";
	if (rail.getNextNode()) {
		os << rail.getNextNode()->getName();
	} else {
		os << "null";
	}
	os << ", lenght=" << rail.getLenght() << ", speedMax=" << rail.getSpeedMax();
	return os;
}
