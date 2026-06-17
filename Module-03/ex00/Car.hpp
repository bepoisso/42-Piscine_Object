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
	void shift_gears_up();
	void shift_gears_down();
	void reverse();
	void turn_wheel(float angle);
	void straighten_wheels();
	void apply_force_on_brakes(float force);
	void apply_emergency_brakes();

};

Car::Car(/* Data */) {
}

Car::~Car() {
}

Car::Car(const Car &other) {
	*this = other;
}

Car &Car::operator=(const Car &other) {
	if (this != &other) {
	}
	return *this;
}

/* Methode */
void Car::start() {
	_engine.start();
}

void Car::stop() {
	_engine.stop();
	_brake.apply_force_on_brakes(100.0f);
}

void Car::accelerate(float speed) {
	_speed.accelerate(speed);
}

void Car::shift_gears_up() {
	if (_gearbox.getCurrent() < 6)
		_gearbox.shift_gears_up();
}

void Car::shift_gears_down() {
	if (_gearbox.getCurrent() > 0)
		_gearbox.shift_gears_down();
}

void Car::reverse() {
	if (_gearbox.getCurrent() == 0)
		_gearbox.reverse();
}

void Car::turn_wheel(float angle) {
	_steering.turn_wheel(angle);
}

void Car::straighten_wheels() {
	_steering.straighten_wheels();
}

void Car::apply_force_on_brakes(float force) {
	_brake.apply_force_on_brakes(force);
}

void Car::apply_emergency_brakes() {
	_brake.apply_emergency_brakes();
}
