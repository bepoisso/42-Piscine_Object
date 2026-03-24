#include "Gearbox.hpp"

Gearbox::Gearbox() {
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
void	Gearbox::shift_gears_up() {
	std::cout << "Shifting up" << std::endl;
}

void	Gearbox::shift_gears_down() {
	std::cout << "Shifting down" << std::endl;
}

void	Gearbox::reverse() {
	std::cout << "Reversing" << std::endl;
}
