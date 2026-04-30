#include "Train.hpp"

static int _nextID = 0;

Train::Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake, Node* p_departure,
	Node* p_arrival, std::string p_depTime, std::string p_stopTime)
: AMovement(p_weight, p_friction, p_acceleration, p_brake), _ID(_nextID++), _name(p_name), _departureStation(p_departure),
	_arrivalStation(p_arrival), _departureTime(p_depTime), _stopTime(p_stopTime)
{
	_currentNode = p_departure;
	_currentRail = NULL;
	std::cout << "[TRAIN] " << p_name << ", weight:" << p_weight << " ton, fricton:" << p_friction << ", acceleration max:" << p_acceleration
		<< " KN, brake force max:" << p_brake << " KN, departure: " << p_departure->getName() << " arrival: " << p_arrival->getName()
		<< ", departure time:" << p_depTime << ", stop time:"  << p_stopTime << ", Created" << std::endl;
}

Train::~Train() {
}

double	Train::getCurrentSpeedLimit() const {
	if (_currentRail)
		return _currentRail->getSpeedMax();
	return -1.0;
}
