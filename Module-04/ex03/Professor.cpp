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
	std::vector<Student*> studentsList = _currentCourse->getStudents();

	for (size_t i = 0; i < studentsList.size(); ++i) {
		studentsList[i]->receiveLesson();
	}
}

void Professor::closeCourse(Headmaster* headmaster) {
	std::vector<Student*> studentsList = _currentCourse->getStudents();

	for (size_t i = 0; i < studentsList.size(); ++i) {
		if (studentsList[i]->getCurrentScore() > _currentCourse->getNumberOfClassToGraduate())
			needGraduateStudent(headmaster, studentsList[i])
	}
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
