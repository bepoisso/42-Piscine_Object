#include "NeedCourseCreationForm.hpp"

#include <iostream>
#include <cstdlib>

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation), _name(""), _professor(NULL), _weeklyHours(0) {
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
	if (_name == "") {
		std::cout << "NeedCourseCreationForm execution refused: name is missing" << std::endl;
		return;
	}
	if (!_professor) {
		std::cout << "NeedCourseCreationForm execution refused: no professor for this course" << std::endl;
		return;
	}
	if (!getIsSigned()) {
		std::cout << "NeedCourseCreationForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!getIsDataFilled()) {
		std::cout << "NeedCourseCreationForm execution refused: missing course plan data" << std::endl;
		return;
	}
	
	Headmaster* mediator = _professor->getheadmasterMediator();
	if (!mediator) {
		std::cout << "NeedCourseCreationForm execution warning: professor has no headmaster mediator" << std::endl;
		return;
	}
	Course* newCourse = mediator->getCourse(_name);
	if (!newCourse) {
		std::cout << "NeedCourseCreationForm execution warning: can create course" << std::endl;
		return;
	}
	std::cout << "Course created: " << _name << " assigned to " << _professor->getName()
	<< " (" << _weeklyHours << "h/week)" << std::endl;
	newCourse->assign(_professor);
	_professor->setCourse(newCourse);
	newCourse->setMaximumNumberOfStudent((rand() % 15 + 5));
	newCourse->setNumberOfClassToGraduate((rand() % 45 + 50));
}
