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
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();
};
