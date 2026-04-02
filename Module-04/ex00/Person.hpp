#pragma once

#include <string>

#include "Foward.hpp"

class Person
{
private:
	std::string _name;
	Room* _currentRoom;                    // non-owning: Room is managed elsewhere
public:
	Person(std::string p_name);
	virtual ~Person();
	Room* room() {return (_currentRoom);}
};
