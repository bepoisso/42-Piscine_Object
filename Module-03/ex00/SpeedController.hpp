#pragma once

#include <iostream>

class SpeedController {
private:
	// Attributes

public:
	// Canonical Form
	SpeedController();
	~SpeedController();
	SpeedController(const SpeedController &other);
	SpeedController &operator=(const SpeedController &other);

/* Methode */
void	accelerate(float speed);

};

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
	std::cout << "accelerating to " << speed << " km/h" << std::endl;
}
