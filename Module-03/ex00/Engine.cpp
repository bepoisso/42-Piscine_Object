#include "Engine.hpp"

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
