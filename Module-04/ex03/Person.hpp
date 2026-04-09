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

	Room* getCurrentRoom() { return _currentRoom; }
	void setCurrentRoom(Room* newRoom) { _currentRoom = newRoom; }
	std::string getName() { return _name; }


};
