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
