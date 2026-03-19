#pragma once

#include "Tool.hpp"

class Worker;

class Hammer : public Tool
{
private:
	int numberOfUses;
	Worker *owner;
	
public:
	Hammer();
	~Hammer();

	void use();
	void setOwner(Worker *newWorker);
	Worker *getOwner();
};
