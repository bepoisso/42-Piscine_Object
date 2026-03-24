#include "Car.hpp"

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
}

void Car::accelerate(float speed) {
	_speed.accelerate(speed);
}

void Car::shift_gears_up() {
	_gearbox.shift_gears_up();
}

void Car::shift_gears_down() {
	_gearbox.shift_gears_down();
}

void Car::reverse() {
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
