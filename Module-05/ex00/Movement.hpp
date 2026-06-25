/**
 * @file Movement.hpp
 * @brief AMovement class - Abstract train dynamics
 * 
 * @details
 * Implements movement physics and state transitions for a train. Concrete
 * trains provide identifiers and speed limits.
 * 
 * @note
 * principles Abstraction, Encapsulation
 */

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
	long int				_deltaTime;				//		seconde

	// FORCE
	double					_frictionForce;
	const double			_gravity;

	// DYNAMIC
	double					_velocity;				//		m/s
	double					_acceleration;
	double					_distanceRemaining;		//		meter

	TrainState				_currentState;

	void accelerateMove();
	void brakeMove();
	void maintainMove();
	void stopMove();

	void updateVelocity();

public:
	AMovement(int p_weight, double p_friction, double p_accelerate, double p_brake);
	virtual ~AMovement() {}

	void 				move(TrainState event);
	virtual std::string	getName() const = 0;
	virtual double		getCurrentSpeedLimit() const = 0;
	void 				setDeltaTime(long int p_dt) { _deltaTime = p_dt; }

	// INITIAL SETTING
	double 		getWeight() 				const { return _mass; }
	double		getFrictionCoefficient()	const { return _coefficientFriction; }
	double		getTractionMax() 			const { return _tractionMax; }
	double		getBrakeMax() 				const { return _brakeMax; }
	// FORCE
	double		getFrictionForce()			const { return _frictionForce; }
	double		getGravity()				const { return _gravity; }

	// DYNAMIC
	double		getCurrentVelocity()		const { return _velocity; }
	double		getCurrentAcceleration()	const { return _acceleration; }
	double		getDistanceRemaining()		const { return _distanceRemaining; }
	TrainState 	getCurrentState()			const { return _currentState; }

	void		setDistanceRemaining(double p_dist)		{ _distanceRemaining = p_dist; }
};
