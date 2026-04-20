#pragma once

#include <vector>
#include <iostream>

#include "Foward.hpp"
#include "Person.hpp"

class Room
{
private:
	long long _ID;
	std::vector<Person*> _occupants;

public:
	Room(long long p_ID);
	bool canEnter(Person* person);
	void enter(Person* person);
	void exit(Person* person);
	
	void printOccupant();
	long long getID() { return _ID; }
};
