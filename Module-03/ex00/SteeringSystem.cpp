#include "SteeringSystem.hpp"

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
