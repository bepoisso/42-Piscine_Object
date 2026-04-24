#pragma once

#include "Foward.hpp"
#include "Room.hpp"


class StaffRestRoom : public Room
{
private:

public:
	StaffRestRoom() : Room(-3, 1) {std::cout << "[Room] Staff rest room was created with a level " << getPrivilege() << " access badge " << std::endl;}
	void enterMessage() { std::cout << "Staff rest room" << std::endl; }
};
