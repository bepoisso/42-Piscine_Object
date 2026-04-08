#include "Professor.hpp"

#include <iostream>

#include "Course.hpp"

Professor::Professor(const std::string& p_name) : Staff(p_name), _currentCourse(0) {
}

void Professor::assignCourse(Course* p_course) {
	_currentCourse = p_course;
	if (_currentCourse)
		_currentCourse->assign(this);
	std::cout << getName() << " is now responsible for a course." << std::endl;
}

void Professor::doClass() {
	if (!_currentCourse) {
		std::cout << getName() << " has no course to teach." << std::endl;
		return;
	}
	std::cout << getName() << " teaches " << _currentCourse->getName() << std::endl;
	_currentCourse->teachSession();
}

void Professor::closeCourse() {
	_currentCourse = 0;
}

Course* Professor::getCurrentCourse() const {
	return _currentCourse;
}
