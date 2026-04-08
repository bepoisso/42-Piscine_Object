#pragma once

#include <vector>

#include "Foward.hpp"

class Room
{
private:
	long long _ID;
	std::vector<Person*> _occupants;
	static long long _nextID;

public:
	Room();
	virtual ~Room();

	long long getID() const;
	virtual bool canEnter(Person* p_person) const;
	virtual void enter(Person* p_person);
	virtual void exit(Person* p_person);
	std::size_t occupantCount() const;
};
