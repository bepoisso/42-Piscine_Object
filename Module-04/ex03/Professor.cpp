#include "Professor.hpp"

#include <iostream>
#include <cmath>

Professor::Professor(std::string p_name) : Staff(p_name), _currentCourse(NULL) {
}

void Professor::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}

void Professor::doClass() {
	std::cout << "Professor " << getName() << " do class of " << _currentCourse->getName() << std::endl;
}

void Professor::closeCourse() {
	_currentCourse = NULL;
}

void Professor::needGraduateStudent(Headmaster* headmaster, Student* student) {
	if (!headmaster || !student) {
		std::cout << "Professor cannot request graduation: invalid mediator or student" << std::endl;
		return;
	}
	if (!_currentCourse) {
		std::cout << "Professor cannot request graduation: no assigned course" << std::endl;
		return;
	}

	Form* form = headmaster->requestForm(CourseFinished);
	CourseFinishedForm* graduateForm = dynamic_cast<CourseFinishedForm*>(form);
	if (!graduateForm) {
		std::cout << "Professor cannot request graduation: wrong form type received" << std::endl;
		return;
	}

	graduateForm->fillCourseResult(student, _currentCourse, 50 + (std::rand() % 50));
	headmaster->submitForm(graduateForm);
}
