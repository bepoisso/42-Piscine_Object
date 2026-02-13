#include <iostream>
#include "Worker.hpp"

Worker::Worker(std::string newName) : name(newName), shovel(NULL) {
	std::cout << "Worker constructor called" << std::endl;
}

Worker::~Worker() {
	std::cout << "Worker destructor called" << std::endl;
}

void Worker::giveShovel(Shovel *newShovel) {
	if (newShovel != NULL && newShovel->getOwner() != NULL && newShovel->getOwner() != this) {
		std::cout << name << ": Removing shovel form the previous owner" << std::endl;
		newShovel->getOwner()->removeShovel();
	}

	shovel = newShovel;
	if (shovel != NULL)
		shovel->setOwner(this);
	std::cout << name << ": Shovel was give" << std::endl;
}

void Worker::removeShovel() {
	if (shovel == NULL) {
		std::cout << name << ": Worker don't have shovel" << std::endl;
		return;
	}
	shovel->setOwner(NULL);
	shovel = NULL;
	std::cout << name << ": Shovel was remove" << std::endl;
}

void Worker::takeShovel() {
	if (shovel == NULL) {
		std::cout << name << ": Don't have any shovel" << std::endl;
		return;
	}
	std::cout << name << ": Shovel was take" << std::endl;
	shovel->use();
}

