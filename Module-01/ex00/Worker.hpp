#pragma once

#include "Struct.hpp"
#include "Shovel.hpp"

class Shovel;

class Worker
{
private:
	std::string name;
	Position pos;
	Statistic stat;
	Shovel *shovel;

public:
	Worker(std::string newName);
	~Worker();

	void giveShovel(Shovel *newShovel);
	void removeShovel();
	void takeShovel();
};
