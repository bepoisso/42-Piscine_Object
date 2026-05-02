#include "Movement.hpp"


AMovement::AMovement(int p_weight, double p_friction, double p_accelerate, double p_brake):
	_mass(p_weight * 1000), _coefficientFriction(p_friction), _tractionMax(p_accelerate * 1000),_brakeMax(p_brake * 1000),
	_gravity(G_gravity)
{
	_frictionForce = _coefficientFriction * _mass * _gravity;
	_velocity = 0;
	_acceleration = 0;
	_distanceRemaining = 0;
}

void AMovement::accelerateMove() {
	double netForce = _tractionMax - _frictionForce;
	if (netForce < 0)
		_acceleration = 0;
	else
		_acceleration = netForce / _mass;
	updateVelocity();
	_currentState = ACCELERATING;
}

void AMovement::brakeMove() {
	double netForce = -_brakeMax - _frictionForce;
	_acceleration = netForce / _mass;
	updateVelocity();
	_currentState = BRAKING;
}

void AMovement::maintainMove() {
	_acceleration = -_frictionForce / _mass;
	updateVelocity();
	_currentState = MAINTAINING;
}

void AMovement::stopMove() {
	_velocity = 0;
	_acceleration = 0;
	_currentState = STOPPED;
}

void AMovement::updateVelocity() {
	double maxSpeed = getCurrentSpeedLimit();
	if (maxSpeed == -1.0)
		throw std::runtime_error("Fail to get Current Speed Limit");
	else
		maxSpeed *= 1000;
	_velocity += _acceleration * _deltaTime;
	if (_velocity > maxSpeed)
		_velocity = maxSpeed;
	if (_velocity < 0)
		_velocity = 0;
	_distanceRemaining -= _velocity * _deltaTime;
	if (_distanceRemaining < 0)
		_distanceRemaining = 0;
}


void AMovement::move(TrainState event) {
	if (event == ACCELERATING)
		accelerateMove();
	else if (event == MAINTAINING)
		maintainMove();
	else if (event == BRAKING)
		brakeMove();
	else if (event == STOPPED)
		stopMove();
	else
		throw std::runtime_error("[TRAIN] " + getName() + ": bad movement event");
}
