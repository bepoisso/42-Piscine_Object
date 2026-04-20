#include "NeedCourseCreationForm.hpp"

#include <iostream>
#include <cstdlib>

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation), _name(""), _weeklyHours(0) {
}

void NeedCourseCreationForm::fillCoursePlan(std::string newName, Professor* newProfessor, int p_weeklyHours) {
	_name = newName;
	_professor = newProfessor;
	_weeklyHours = p_weeklyHours;
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
	newCourse->setMaximumNumberOfStudent((rand() % 10 + 1));
	newCourse->setNumberOfClassToGraduate((rand() % 41 + 50));
	Headmaster* mediator = _professor->getheadmasterMediator();
	if (!mediator) {
		std::cout << "NeedCourseCreationForm execution warning: professor has no headmaster mediator" << std::endl;
		delete newCourse;
		return;
	}
	mediator->receiveCourse(newCourse);
}

bool NeedCourseCreationForm::isComplete() {
	if (_name == ""){
		std::cout << "NeedCrouseCreationForm not filled (name)" << std::endl;
		return false;
	}
	if (!_professor) {
		std::cout << "NeedCrouseCreationForm not filled (professor)" << std::endl;
		return false;
	}
	if (_weeklyHours <= 0 || _weeklyHours > 10) {
		std::cout << "NeedCourseCreationForm not filled (weeklyHours need beetwen 1 & 10)" << std::endl;
		return false;
	}
	setIsDataFilled(true);
	return true;
}
