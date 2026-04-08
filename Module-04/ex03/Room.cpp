#include "Room.hpp"

#include "Person.hpp"

long long Room::_nextID = 1;

Room::Room() : _ID(_nextID++) {
}

Room::~Room() {
}

long long Room::getID() const {
	return _ID;
}

bool Room::canEnter(Person* p_person) const {
	return (p_person != 0);
}

void Room::enter(Person* p_person) {
	if (!canEnter(p_person))
		return;
	_occupants.push_back(p_person);
	p_person->setRoom(this);
}

void Room::exit(Person* p_person) {
	if (!p_person)
		return;
	for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it) {
		if (*it == p_person) {
			_occupants.erase(it);
			break;
		}
	}
	if (p_person->room() == this)
		p_person->setRoom(0);
}

std::size_t Room::occupantCount() const {
	return _occupants.size();
}
