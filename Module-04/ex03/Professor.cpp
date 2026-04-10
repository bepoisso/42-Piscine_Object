#include "Professor.hpp"

#include <iostream>
#include <cmath>

Professor::Professor(std::string p_name)
	: Staff(p_name), _currentCourse(NULL), _headmasterMediator(NULL) {
}

void Professor::setHeadmasterMediator(Headmaster* headmaster) {
	_headmasterMediator = headmaster;
}

void Professor::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}

void Professor::doClass() {
	if (!_currentCourse) {
		needNewCourse();
		return;
	}

	std::cout << "Professor " << getName() << " do class of " << _currentCourse->getName() << std::endl;
	std::vector<Student*> studentsList = _currentCourse->getStudents();

	for (size_t i = 0; i < studentsList.size(); ++i) {
		studentsList[i]->receiveLesson();
	}
}

void Professor::closeCourse() {
	if (!_currentCourse)
		return;

	std::vector<Student*> studentsList = _currentCourse->getStudents();

	for (size_t i = 0; i < studentsList.size(); ++i) {
		if (studentsList[i]->getCurrentScore() > _currentCourse->getNumberOfClassToGraduate())
			needGraduateStudent(studentsList[i]);
	}
	_currentCourse = NULL;
}

void Professor::needGraduateStudent(Student* student) {
	if (!_headmasterMediator || !student) {
		std::cout << "Professor cannot request graduation: invalid mediator or student" << std::endl;
		return;
	}
	if (!_currentCourse) {
		std::cout << "Professor cannot request graduation: no assigned course" << std::endl;
		return;
	}

	Form* form = _headmasterMediator->requestForm(CourseFinished);
	CourseFinishedForm* graduateForm = dynamic_cast<CourseFinishedForm*>(form);
	if (!graduateForm) {
		std::cout << "Professor cannot request graduation: wrong form type received" << std::endl;
		return;
	}

	graduateForm->fillCourseResult(student, _currentCourse, student->getCurrentScore());
	_headmasterMediator->submitForm(graduateForm);
}

void Professor::needNewCourse() {

	std::string courseName;
	if (!_headmasterMediator) {
		std::cout << "Professor cannot request new course: no mediator" << std::endl;
		return;
	}
	Form* form = _headmasterMediator->requestForm(NeedCourseCreation);
	if (!form) {
		std::cout << "Professor cannot request new course: form unavailable" << std::endl;
		return;
	}
	NeedCourseCreationForm* courseForm = dynamic_cast<NeedCourseCreationForm*>(form);

	switch (std::rand() % 5 + 1)
	{
	case 1:
		courseName = "Algorithms";
		break;
	case 2:
		courseName = "Database Design";
		break;
	case 3:
		courseName = "Operating Systems";
		break;
	default:
		courseName = "Web Developement";
		break;
	}
	int temp = (std::rand() % 10 + 2);

	courseForm->fillCoursePlan(courseName, this, temp);
	_headmasterMediator->submitForm(courseForm);
}
