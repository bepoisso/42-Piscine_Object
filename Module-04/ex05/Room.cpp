#include "Room.hpp"

Room::Room(long long p_ID, unsigned int p_privReq) : _ID(p_ID), _privilegeRequired(p_privReq) {
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
	if (person->getPrivilege() < _privilegeRequired) {
		std::cout << person->printHeader() << person->getName() << " try to enter in a private area!" << std::endl;
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
	std::cout << person->printHeader() << person->getName() << " enter in room no " << _ID << std::endl;
}

void Room::exit(Person* person) {
	if (!person)
		return;
	if (person->getCurrentRoom() == this) {
		person->setCurrentRoom(NULL);
		std::cout << person->printHeader() << person->getName() << " exit room no " << _ID << std::endl;
	}
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		if (*it == person) {
			_occupants.erase(it);
			break;
		}
	}
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

bool Room::isEmpty() {
	if (_occupants.empty())
		return true;
	return false;
}

