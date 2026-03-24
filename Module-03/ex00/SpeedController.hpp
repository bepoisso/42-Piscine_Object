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
