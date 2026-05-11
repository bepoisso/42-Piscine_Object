#pragma once

#include <iostream>

class SteeringSystem {
private:

public:
	// Canonical Form
	SteeringSystem();
	~SteeringSystem();
	SteeringSystem(const SteeringSystem &other);
	SteeringSystem &operator=(const SteeringSystem &other);

/* Methode */
void	turn_wheel(float angle);
void	straighten_wheels();

};

SteeringSystem::SteeringSystem() {
}

SteeringSystem::~SteeringSystem() {
}

SteeringSystem::SteeringSystem(const SteeringSystem &other) {
	*this = other;
}

SteeringSystem &SteeringSystem::operator=(const SteeringSystem &other) {
	if (this != &other) {
	}
	return *this;
}

/* Methode */
void	SteeringSystem::turn_wheel(float angle) {
	std::cout << "Turning wheel by " << angle << " degrees" << std::endl;
}

void	SteeringSystem::straighten_wheels() {
	std::cout << "Straightening wheels" << std::endl;
}
