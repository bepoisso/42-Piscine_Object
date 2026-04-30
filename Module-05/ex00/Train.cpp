#include "Train.hpp"

static int _nextID = 0;

Train::Train(std::string p_name, int p_weight, float p_friction, float p_acceleration, float p_brake, Node* p_departure,
	Node* p_arrival, std::string p_depTime, std::string p_stopTime)
: _ID(_nextID++), _name(p_name), _weight(p_weight), _frictionCoefficient(p_friction), _accelerationMax(p_acceleration),
	_brakeMax(p_brake), _departureStation(p_departure), _arrivalStation(p_arrival), _departureTime(p_depTime), _stopTime(p_stopTime) {
		std::cout << "[TRAIN] " << p_name << ", weight:" << p_weight << " ton, fricton:" << p_friction << ", acceleration max:" << p_acceleration
			<< " KN, brake force max:" << p_brake << " KN, departure: " << p_departure->getName() << " arrival: " << p_arrival->getName()
			<< ", departure time:" << p_depTime << ", stop time:"  << p_stopTime << ", Created" << std::endl;
}

Train::~Train() {
}

