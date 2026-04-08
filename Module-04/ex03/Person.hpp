#pragma once

#include <string>

#include "Foward.hpp"

class Person
{
private:
	std::string _name;
	Room* _currentRoom;

public:
	Person(const std::string& p_name);
	virtual ~Person();

	const std::string& getName() const;
	Room* room() const;
	void setRoom(Room* p_room);
};
