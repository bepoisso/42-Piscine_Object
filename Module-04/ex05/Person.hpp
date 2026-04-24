#pragma once

#include <string>

#include "Foward.hpp"
#include "Room.hpp"

class Person
{
private:
	std::string _name;
	Room* _currentRoom;				// non-owning: owning by School
public:
	Person(std::string p_name);
	virtual ~Person();

	virtual std::string printHeader() = 0;
	Room* getCurrentRoom() { return _currentRoom; }
	void setCurrentRoom(Room* newRoom) { _currentRoom = newRoom; }
	void safeExit();
	std::string getName() { return _name; }
	virtual unsigned int getPrivilege() const { return (0u); }

};
