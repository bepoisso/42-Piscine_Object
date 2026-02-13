#include <iostream>
#include "Shovel.hpp"

Shovel::Shovel() : numberOfUses(0), owner(NULL) {
	std::cout << "Shovel constructor called" << std::endl;
}

Shovel::~Shovel() {
	std::cout << "Shovel destructor called" << std::endl;
}

void Shovel::use() {
	std::cout << "Shovel was used " << ++numberOfUses << " time" << std::endl;
}

void Shovel::setOwner(Worker *newWorker) {
	owner = newWorker;
}

Worker *Shovel::getOwner() {
	return owner;
}

