#pragma once

#include <iostream>

class Gearbox {
private:
	// Attributes
	int _current;

public:
	// Canonical Form
	Gearbox();
	~Gearbox();
	Gearbox(const Gearbox &other);
	Gearbox &operator=(const Gearbox &other);

/* Operator */

/* Getter / Setter */
int getCurrent() const;

/* Methode */
void	shift_gears_up();
void	shift_gears_down();
void	reverse();

};

Gearbox::Gearbox(): _current(0) {
}

Gearbox::~Gearbox() {
}

Gearbox::Gearbox(const Gearbox &other) {
	*this = other;
}

Gearbox &Gearbox::operator=(const Gearbox &other) {
	if (this != &other) {
	}
	return *this;
}

/* Methode */

int Gearbox::getCurrent() const {
	return _current;
}

void	Gearbox::shift_gears_up() {
	_current++;
	std::cout << "Shifting up. Gear [" << _current << "] engaged." << std::endl;
}

void	Gearbox::shift_gears_down() {
	_current--;
	std::cout << "Shifting down. Gear [" << _current << "] engaged." << std::endl;
}

void	Gearbox::reverse() {
	_current = -1;
	std::cout << "Reversing engaged" << std::endl;
}
