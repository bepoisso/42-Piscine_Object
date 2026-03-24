#include "SpeedController.hpp"

SpeedController::SpeedController() {
}

SpeedController::~SpeedController() {
}

SpeedController::SpeedController(const SpeedController &other) {
	*this = other;
}

SpeedController &SpeedController::operator=(const SpeedController &other) {
	if (this != &other) {
	}
	return *this;
}

/* Methode */
void	SpeedController::accelerate(float speed) {
	std::cout << "SpeedController: accelerating to " << speed << " km/h" << std::endl;
}
