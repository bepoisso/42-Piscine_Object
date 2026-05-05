#include "Train.hpp"

static int _nextID = 0;

Train::Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake, Node* p_departure,
	Node* p_arrival, std::string p_depTime, std::string p_stopTime)
: AMovement(p_weight, p_friction, p_acceleration, p_brake), AClock(), _ID(_nextID++), _name(p_name), _departureStation(p_departure),
	_arrivalStation(p_arrival), _pathIndex(0), _hasStart(false), _finish(false), _departureTime(Time(p_depTime)), _stopTime(Time(p_stopTime)), _waitingTime(Time(0))
{
	std::cout << "[TRAIN] " << p_name << ", weight:" << p_weight << " ton, fricton:" << p_friction << ", acceleration max:" << p_acceleration
		<< " KN, brake force max:" << p_brake << " KN, departure: " << p_departure->getName() << " arrival: " << p_arrival->getName()
		<< ", departure time:" << _departureTime << ", stop time:"  << _stopTime << ", Created" << std::endl;
}

Train::~Train() {
}

double	Train::getCurrentSpeedLimit() const {
	if (_currentRail)
		return _currentRail->getSpeedMax();
	return 0;
}

double	Train::getTotalDistance()	const {
	double result = 0.0;
	size_t i = 0;
	while (i < _path.size() - 1) {
		if (!_path[i] || !_path[i + 1])
			throw std::runtime_error("node[index] or node[index + 1] is nill can't get total distance");
		Rail* r = _mediator->getGraph()->getRail(_path[i], _path[i + 1]);
		if (!r)
			throw std::runtime_error("rail is nill can't get total distance");
		result += r->getLenght();
		++i;
	}
	return result;
}

double	Train::getTotalRemaining()	const {
	double dTot = getTotalDistance();
	double dPassed = 0.0;
	if (!_currentRail || _pathIndex <= 0)
		return dTot;
	dPassed += _currentRail->getLenght() - getDistanceRemaining();
	size_t i = _pathIndex - 1;
	while (i > 0) {
		if (!_path[i] || !_path[i - 1])
			throw std::runtime_error("node[index] or node[index - 1] is nill can't get total remaining");
		Rail* r = _mediator->getGraph()->getRail(_path[i - 1], _path[i]);
		if (!r)
			throw std::runtime_error("rail is nill can't get total remaining");
		dPassed += r->getLenght();
		--i;
	}
	return dTot - dPassed;
}

int Train::getPos() const {
	if (!_currentRail)
		return 0;
	return (int)((_currentRail->getLenght() - getDistanceRemaining()) / 1000);
}

Rail* Train::getNextRail() const {
	if (_to == _arrivalStation)
		return NULL;
	return _mediator->getGraph()->getRail(_to, _path[_pathIndex + 1]);
}


void Train::goToNextRail() {
	if (_pathIndex >= _path.size() - 1) {
		move(STOPPED);
		_finish = true;
		return;
	}
	
	_from = _path[_pathIndex];
	_to = _path[_pathIndex + 1];
	_currentRail = _mediator->getGraph()->getRail(_from, _to);
	setDistanceRemaining(_currentRail->getLenght());
	++_pathIndex;
}

void Train::update(long int p_dt) {
	setDeltaTime(p_dt);
	add(p_dt);

	if (!_hasStart) {
		if (getCurrentTime() >= _departureTime) {
			_hasStart = true;
			goToNextRail();
		}
		else
			return;
	}

	double distance = getDistanceRemaining();
	double tDeccel = (getBrakeMax() + getFrictionForce()) / getWeight();
	double dBrake = (getCurrentVelocity() * getCurrentVelocity()) / (2.0 * tDeccel);

	if (getCurrentState() == BRAKING && _to->isStation() && getCurrentVelocity() > 0.0) {
		move(BRAKING);
		return;
	}
	if (distance > dBrake && getCurrentVelocity() < _currentRail->getSpeedMax())
		move(ACCELERATING);
	else if (distance > dBrake)
		move(MAINTAINING);
	else if (distance > 0.0) {
		Rail* r = getNextRail();
		if (_to->isStation() || r->getSpeedMax() < getCurrentVelocity()) {
			move(BRAKING);
		}
		else
			move(MAINTAINING);
	}
	else if (distance <= 0) {
		if (_to->isStation()) {
			if (_waitingTime < _stopTime) {
				_waitingTime = _waitingTime + p_dt;
				move(STOPPED);
				return;
			}
			else
				_waitingTime = Time(0);
		}
		goToNextRail();
	}
}
