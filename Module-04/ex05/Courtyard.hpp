#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class Courtyard : public Room
{
private:

public:
	Courtyard() : Room(-1, 0) { std::cout << "[Room] Courtyard was created" << std::endl; }
	void enterMessage() { std::cout << "Courtyard" << std::endl; }

};
