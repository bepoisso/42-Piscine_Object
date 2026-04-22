#include "Room.hpp"

Room::Room(long long p_ID) : _ID(p_ID) {
}

bool Room::canEnter(Person* person) {
	if (!person)
		return false;
	if (person->getCurrentRoom() == this)
		return false;
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		if (*it == person)
			return false;
	}
	return true;
}

void Room::enter(Person* person) {
	if (!canEnter(person))
		return;
	if (person->getCurrentRoom() != NULL)
		person->getCurrentRoom()->exit(person);
	_occupants.push_back(person);
	person->setCurrentRoom(this);
}

void Room::exit(Person* person) {
	if (!person)
		return;
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		if (*it == person) {
			_occupants.erase(it);
			break;
		}
	}
	if (person->getCurrentRoom() == this)
		person->setCurrentRoom(NULL);
}

void Room::printOccupant() {
	std::cout << "---Occupant list of " << _ID << "---" << std::endl;
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		std::cout << (*it)->getName() << std::endl;
	}
}

bool Room::isPresent(Person* p_person) {
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		if ((*it) == p_person)
			return true;
	}
	return false;
}

