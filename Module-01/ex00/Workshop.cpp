#include <iostream>

#include "Workshop.hpp"

Workshop::Workshop(std::string newName) : name(newName) {
	std::cout << "Workshop constructor called" << std::endl;
}

Workshop::~Workshop() {
	while (!workers.empty())
		releaseWorker(workers.back());
	std::cout << "Workshop destructor called" << std::endl;
}

Workshop::Workshop(const Workshop &other) : name(other.name), workers(other.workers) {
	std::cout << "Workshop copy constructor called" << std::endl;
}

Workshop &Workshop::operator=(const Workshop &other) {
	if (this != &other) {
		name = other.name;
		workers = other.workers;
	}
	return (*this);
}

void Workshop::registerWorker(Worker *worker) {
	if (worker == NULL) {
		std::cout << name << ": invalid worker" << std::endl;
		return;
	}

	for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it) {
		if (*it == worker) {
			std::cout << name << ": worker already registered" << std::endl;
			return;
		}
	}

	workers.push_back(worker);
	worker->addWorkshop(this);
	std::cout << name << ": worker registered" << std::endl;
}

void Workshop::releaseWorker(Worker *worker) {
	if (worker == NULL) {
		std::cout << name << ": invalid worker" << std::endl;
		return;
	}

	for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it) {
		if (*it == worker) {
			workers.erase(it);
			worker->removeWorkshop(this);
			std::cout << name << ": worker released" << std::endl;
			return;
		}
	}

	std::cout << name << ": worker not found" << std::endl;
}

void Workshop::executeWorkDay() {
	if (workers.empty()) {
		std::cout << name << ": no worker registered" << std::endl;
		return;
	}

	std::cout << name << ": work day start" << std::endl;
	for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it) {
		if (*it != NULL)
			(*it)->work(this);
	}
	std::cout << name << ": work day end" << std::endl;
}
