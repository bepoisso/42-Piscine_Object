#include "Train.hpp"

static int _nextID = 0;

Train::Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake, Node* p_departure,
	Node* p_arrival, std::string p_depTime, std::string p_stopTime)
: AMovement(p_weight, p_friction, p_acceleration, p_brake), AClock(), _ID(_nextID++), _name(p_name), _departureStation(p_departure),
	_arrivalStation(p_arrival), _pathIndex(0), _hasStart(false), _finish(false), _departureTime(p_depTime), _stopTime(p_stopTime), _waitingTime(Time(0))
{
	std::cout << "[TRAIN] " << p_name << ", weight:" << p_weight << " ton, fricton:" << p_friction << ", acceleration max:" << p_acceleration
		<< " KN, brake force max:" << p_brake << " KN, departure: " << p_departure->getName() << " arrival: " << p_arrival->getName()
		<< ", departure time:" << p_depTime << ", stop time:"  << p_stopTime << ", Created" << std::endl;
}

Train::~Train() {
}

double	Train::getCurrentSpeedLimit() const {
	if (_currentRail)
		return _currentRail->getSpeedMax();
	return 0;
}

void Train::goToNextRail() {
	++_pathIndex;
	if (_pathIndex >= _path.size() - 1) {
		move(STOPPED);
		_finish = true;
		return;
	}

	_from = _path[_pathIndex];
	_to = _path[_pathIndex + 1];
	_currentRail = _mediator->getGraph()->getRail(_from, _to);
	setDistanceRemaining(_currentRail->getLenght());
}

void Train::update(long int p_dt) {
	setDeltaTime(p_dt);
	add(p_dt);

	double distance = getDistanceRemaining();
	double tDeccel = (getBrakeMax() + getFrictionForce()) / getWeight();
	double dBrake = (getCurrentVelocity() * getCurrentVelocity()) / (2 * tDeccel);

	if (!_hasStart) {
		if (getCurrentTime() >= _departureTime)
			_hasStart = true;
		else
			return;
	}
	if (distance <= 0 && _to->isStation()) {
		if (_waitingTime < _stopTime) {
			_waitingTime = _waitingTime + p_dt;
			move(STOPPED);
			return;
		}
		else
			_waitingTime = Time(0);
	}

	if (distance > dBrake + 200)
		move(ACCELERATING);
	else if (distance > dBrake)
		move(MAINTAINING);
	else if (distance > 0)
		move(BRAKING);
	else {
		move(STOPPED);
		goToNextRail();
	}
}
