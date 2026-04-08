#pragma once

#include <vector>

#include "Foward.hpp"

class Room
{
private:
	long long _ID;
	std::vector<Person*> _occupants;       // non-owning: Persons are managed elsewhere

public:
	Room();
	bool canEnter(Person* person);
	void enter(Person* person);
	void exit(Person* person);
	
	void printOccupant();
};
