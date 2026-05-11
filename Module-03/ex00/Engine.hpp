#pragma once

#include <iostream>

class Engine {
private:
	// Attributes

public:
	// Canonical Form
	Engine(/* Data */);
	~Engine();
	Engine(const Engine &other);
	Engine &operator=(const Engine &other);

/* Operator */

/* Getter / Setter */

/* Methode */
void	start();
void	stop();


};

Engine::Engine() {
}

Engine::~Engine() {
}

Engine::Engine(const Engine &other) {
	*this = other;
}

Engine &Engine::operator=(const Engine &other) {
	if (this != &other) {
	}
	return *this;
}

/* Methode */
void	Engine::start() {
	std::cout << "Engine start" << std::endl;
}

void	Engine::stop() {
	std::cout << "Engine stop" << std::endl;
}
