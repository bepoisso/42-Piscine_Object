#pragma once

#include <vector>
#include <iostream>

#include "Foward.hpp"
#include "Person.hpp"

class Room
{
private:
	long long _ID;
	const unsigned int _privilegeRequired;
	std::vector<Person*> _occupants;

public:
	Room(long long p_ID, const unsigned int p_privReq);
	bool canEnter(Person* person);
	void enter(Person* person);
	void exit(Person* person);
	bool isPresent(Person* p_person);
	bool isEmpty();
	
	void printOccupant();
	long long getID() { return _ID; }
};
