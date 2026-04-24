#include "Classroom.hpp"

long long Classroom::_nextId = 1;

Classroom::Classroom() : Room(_nextId++, 0), _currentCourse(NULL) {
}

void Classroom::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}
