#pragma once

#include <iostream>

class Gearbox {
private:
	// Attributes

public:
	// Canonical Form
	Gearbox(/* Data */);
	~Gearbox();
	Gearbox(const Gearbox &other);
	Gearbox &operator=(const Gearbox &other);

/* Operator */

/* Getter / Setter */

/* Methode */
void	shift_gears_up();
void	shift_gears_down();
void	reverse();

};
