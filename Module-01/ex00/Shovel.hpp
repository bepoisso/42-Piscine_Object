#pragma once

#include "Worker.hpp"

class Worker;

class Shovel
{
private:
	int numberOfUses;
	Worker *owner;
	
public:
	Shovel();
	~Shovel();

	void use();
	void setOwner(Worker *newWorker);
	Worker *getOwner();
};
