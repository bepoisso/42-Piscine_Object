#include <iostream>
#include "Hammer.hpp"

Hammer::Hammer() : numberOfUses(0), owner(NULL) {
	std::cout << "Hammer constructor called" << std::endl;
}

Hammer::~Hammer() {
	std::cout << "Hammer destructor called" << std::endl;
}

void Hammer::use() {
	std::cout << "Hammer was used " << ++numberOfUses << " time" << std::endl;
}

void Hammer::setOwner(Worker *newWorker) {
	owner = newWorker;
}

Worker *Hammer::getOwner() {
	return owner;
}

