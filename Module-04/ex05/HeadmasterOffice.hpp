#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class HeadmasterOffice : public Room
{
private:

public:
	HeadmasterOffice() : Room(-5, 3) {std::cout << "[Room] Headmaster's office was created with a level " << getPrivilege() << " access badge " << std::endl;}
	void enterMessage() { std::cout << "Headmaster's office" << std::endl; }
};
