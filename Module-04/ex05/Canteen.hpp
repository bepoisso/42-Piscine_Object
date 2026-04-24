#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class Canteen : public Room
{
private:

public:
	Canteen() : Room(-2, 0) { std::cout << "[Room] Cafeteria was created with a level " << getPrivilege() << " access badge " << std::endl; }
	void enterMessage() { std::cout << "Cafeteria" << std::endl; }
};
