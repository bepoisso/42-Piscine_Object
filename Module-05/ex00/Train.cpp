#include "Train.hpp"

static int _nextID = 0;

Train::Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake, Node* p_departure,
	Node* p_arrival, std::string p_depTime, std::string p_stopTime)
: AMovement(p_weight, p_friction, p_acceleration, p_brake), AClock(), _ID(_nextID++), _name(p_name), _departureStation(p_departure),
	_arrivalStation(p_arrival), _pathIndex(0), _mediator(nullptr), _currentRail(nullptr), _from(nullptr), _to(nullptr), _hasStart(false),
	_finish(false), _departureTime(Time(p_depTime)), _stopTime(Time(p_stopTime)), _waitingTime(Time(0))
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
	size_t i = 0;
	if (_pathIndex <= 0)
		return dTot;
	if (_currentRail) {
		dPassed += _currentRail->getLenght() - getDistanceRemaining();
		i = _pathIndex - 1;
	}
	else
		i = _pathIndex;
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

int Train::getPos(Rail* r, Node* target) const {
	Rail* current;
	bool railSwitch;
	bool directionOK;
	
	if (!_currentRail) {
		railSwitch = true;
		current = getNextRail();
		if (_path[_pathIndex] == target)
			directionOK = false;
		else
			directionOK = true;
	}
	else {
		railSwitch = false;
		current = _currentRail;
		if (_to == target)
			directionOK = true;
		else
			directionOK = false;
	}
	
	if (current != r)
		return -1;
	
	if (!railSwitch) {
		if (directionOK)
			return (int)((current->getLenght() - getDistanceRemaining()) / 1000);
		else
			return (int)(getDistanceRemaining() / 1000);
	}
	else {
		if (directionOK)
			return 0;
		else
			return (int)(current->getLenght() / 1000);
	}
	return -1;
}

Rail* Train::getNextRail() const {
	if (_to == _arrivalStation)
		return NULL;
	if (_to == nullptr)
		return _mediator->getGraph()->getRail(_path[0], _path[1]);
	return _mediator->getGraph()->getRail(_to, _path[_pathIndex + 1]);

}

Rail* Train::getPrevRail() const {
	if (_from == _departureStation)
		return NULL;
	if (_from == nullptr)
		return _mediator->getGraph()->getRail(_path[0], _path[1]);
	return _mediator->getGraph()->getRail(_from, _to);

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
			if (_mediator->isSafeToEnterNextRail(this)) {
				_hasStart = true;
				goToNextRail();
			}
			else
				return;
		}
		else
			return;
	}

	double distance = getDistanceRemaining();
	double tDeccel = (getBrakeMax() + getFrictionForce()) / getWeight();
	double dBrake = (getCurrentVelocity() * getCurrentVelocity()) / (2.0 * tDeccel);
	bool isCollisonRisk = _mediator->isCollisionRisk(this);
	bool safeEnterNextRail = _mediator->isSafeToEnterNextRail(this);

	if (isCollisonRisk)
		move(BRAKING);
	else if (getCurrentState() == BRAKING && getCurrentVelocity() > 0.0 && (_to->isStation() || !safeEnterNextRail))
		move(BRAKING);
	else if (distance > dBrake && getCurrentVelocity() < _currentRail->getSpeedMax())
		move(ACCELERATING);
	else if (distance > dBrake)
		move(MAINTAINING);
	else if (distance > 0.0) {
		Rail* r = getNextRail();
		if (!safeEnterNextRail || _to->isStation() || getCurrentVelocity() > r->getSpeedMax()) {
			move(BRAKING);
		}
		else
			move(MAINTAINING);
	}
	else if (distance <= 0) {
		_currentRail = NULL;
		if (_to->isStation()) {
			if (_waitingTime < _stopTime) {
				_waitingTime = _waitingTime + p_dt;
				move(STOPPED);
				return;
			}
		}
		if (!safeEnterNextRail) {
			move(STOPPED);
			return;
		}
		_waitingTime = Time(0);
		goToNextRail();
	}
}
