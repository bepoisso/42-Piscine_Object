#include "Room.hpp"

Room::Room(long long p_ID) : _ID(p_ID) {
}

bool Room::canEnter(Person* person) {
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		if (*it == person) {
			return true;
		}
	}
	return false;
}

void Room::enter(Person* person) {
	person->setCurrentRoom(this);
}

void Room::exit(Person* person) {
	person->setCurrentRoom(NULL);
}

void Room::printOccupant() {
	std::cout << "---Occupant list of " << _ID << "---" << std::endl;
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		std::cout << (*it)->getName() << std::endl;
	}
}

