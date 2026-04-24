#include "Classroom.hpp"

long long Classroom::_nextId = 1;

Classroom::Classroom() : Room(_nextId++, 0), _currentCourse(NULL) {
	std::cout << "[Room] Classroom number " << getID() << " was created " << std::endl;
}

void Classroom::enterMessage() {
	std::cout << "classroom number " << getID() << std::endl;
}

void Classroom::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}
