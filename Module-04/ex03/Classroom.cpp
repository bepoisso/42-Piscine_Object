#include "Classroom.hpp"

Classroom::Classroom() : _currentCourse(0) {
}

void Classroom::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}

void Classroom::clearCourse() {
	_currentCourse = 0;
}

Course* Classroom::getCurrentCourse() const {
	return _currentCourse;
}

bool Classroom::isFree() const {
	return (_currentCourse == 0);
}
