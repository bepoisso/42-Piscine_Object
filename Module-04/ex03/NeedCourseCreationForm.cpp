#include "NeedCourseCreationForm.hpp"

#include <iostream>
#include <cstdlib>

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation), _name(""), _weeklyHours(0) {
}

void NeedCourseCreationForm::fillCoursePlan(std::string newName, Professor* newProfessor, int p_weeklyHours) {
	_name = newName;
	_professor = newProfessor;
	_weeklyHours = p_weeklyHours;
	if (_name == "" || !_professor)
		setIsDataFilled(false);
	else
		setIsDataFilled(true);
}

void NeedCourseCreationForm::execute() {
	if (!getIsSigned()) {
		std::cout << "NeedCourseCreationForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!getIsDataFilled()) {
		std::cout << "NeedCourseCreationForm execution refused: missing course plan data" << std::endl;
		return;
	}
	std::cout << "Course created: " << _name << " assigned to " << _professor->getName()
		<< " (" << _weeklyHours << "h/week)" << std::endl;

	Course* newCourse = new Course(_name);
	newCourse->assign(_professor);
	_professor->setCourse(newCourse);
	newCourse->setMaximumNumberOfStudent((rand() % 10 + 5));
	newCourse->setNumberOfClassToGraduate((rand() % 41 + 50));
	Headmaster* mediator = _professor->getheadmasterMediator();
	if (!mediator) {
		std::cout << "NeedCourseCreationForm execution warning: professor has no headmaster mediator" << std::endl;
		delete newCourse;
		return;
	}
	mediator->receiveCourse(newCourse);
}
