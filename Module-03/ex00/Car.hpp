#pragma once

#include "Engine.hpp"
#include "Gearbox.hpp"
#include "SteeringSystem.hpp"
#include "BrakeSystem.hpp"
#include "SpeedController.hpp"

class Car {
private:
	// Attributes
	Engine			_engine;
	Gearbox			_gearbox;
	SteeringSystem	_steering;
	BrakeSystem		_brake;
	SpeedController	_speed;

public:
	// Canonical Form
	Car();
	~Car();
	Car(const Car &other);
	Car &operator=(const Car &other);

/* Methode */
	void start();
	void stop();
	void accelerate(float speed);
	void shift_gear_up();
	void shift_gear_down();
	void reverse();
	void turn_wheel(float angle);
	void straighten_wheels();
	void apply_force_on_brakes(float force);
	void apply_emergency_brakes();

};
