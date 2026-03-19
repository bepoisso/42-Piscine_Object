#pragma once

#include "Worker.hpp"

class Workshop {
private:
	// Attributes
	std::string name;
	std::vector<Worker*> workers;

public:
	// Canonical Form
	Workshop(std::string newName);
	~Workshop();
	Workshop(const Workshop &other);
	Workshop &operator=(const Workshop &other);

/* Operator */

/* Getter / Setter */

/* Methode */
	void registerWorker(Worker *worker);
	void releaseWorker(Worker *worker);
	void executeWorkDay();

};
