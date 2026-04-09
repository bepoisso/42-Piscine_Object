#include "Classroom.hpp"

Classroom::Classroom() : Room(0), _currentCourse(NULL) {
}

void Classroom::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}
