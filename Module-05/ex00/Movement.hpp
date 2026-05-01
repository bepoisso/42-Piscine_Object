#pragma once

#include <iostream>
#include <string>

#include "Forward.hpp"
#include "Utils.hpp"

class AMovement
{
private:
	// INITIAL SETTING
	const double			_mass;					//		Ton -> Kg
	const double			_coefficientFriction;
	const double			_tractionMax;			//		kN -> N
	const double			_brakeMax;				//		kN -> N

	// FORCE
	double					_frictionForce;
	const double			_gravity;

	// DYNAMIC
	double					_velocity;				//		m/s
	double					_acceleration;
	double					_distanceRemaining;		//		meter
	double					_deltaTime;				//		seconde

	TrainState				_currentState;

	void _accelerateMove();
	void _brakeMove();
	void _maintainMove();
	void _stopMove();

	void _updateVelocity();

public:
	AMovement(int p_weight, double p_friction, double p_accelerate, double p_brake);
	virtual ~AMovement() {}

	void 				move(TrainState event);
	virtual std::string	getName() const = 0;
	virtual double		getCurrentSpeedLimit() const = 0;

	double 	getWeight() 				const { return _mass / 1000; }
	double	getFrictionCoefficient()	const { return _coefficientFriction; }
	double	getTractionMax() 			const { return _tractionMax / 1000; }
	double	getBrakeMax() 				const { return _brakeMax / 1000; }
	double	getGravity()				const { return _gravity; }
};
