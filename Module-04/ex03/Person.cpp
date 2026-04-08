#include "Person.hpp"

Person::Person(const std::string& p_name) : _name(p_name), _currentRoom(0) {
}

Person::~Person() {
}

const std::string& Person::getName() const {
	return _name;
}

Room* Person::room() const {
	return _currentRoom;
}

void Person::setRoom(Room* p_room) {
	_currentRoom = p_room;
}
