#include "BrakeSystem.hpp"

BrakeSystem::BrakeSystem() {
}

BrakeSystem::~BrakeSystem() {
}

BrakeSystem::BrakeSystem(const BrakeSystem &other) {
	*this = other;
}

BrakeSystem &BrakeSystem::operator=(const BrakeSystem &other) {
	if (this != &other) {
	}
	return *this;
}

/* Methode */
void	BrakeSystem::apply_force_on_brakes(float force) {
	std::cout << "Applying " << force << " N of force to the brakes" << std::endl;
}

void	BrakeSystem::apply_emergency_brakes() {
	std::cout << "Emergency brakes are acctivated" << std::endl;
}
