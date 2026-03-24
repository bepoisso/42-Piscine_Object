#pragma once

#include <iostream>

class BrakeSystem {
private:

public:
	// Canonical Form
	BrakeSystem();
	~BrakeSystem();
	BrakeSystem(const BrakeSystem &other);
	BrakeSystem &operator=(const BrakeSystem &other);

/* Methode */
	void	apply_force_on_brakes(float force);
	void	apply_emergency_brakes();

};
