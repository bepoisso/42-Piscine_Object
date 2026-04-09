#include "NeedCourseCreationForm.hpp"

#include <iostream>

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation), _weeklyHours(0), _isCreated(false) {
}

void NeedCourseCreationForm::fillCoursePlan(Course* newCourse, Professor* newProfessor, int p_weeklyHours) {
	_course = newCourse;
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
	_isCreated = true;
	std::cout << "Course created: " << _course->getName() << " assigned to " << _professor->getName()
		<< " (" << _weeklyHours << "h/week)" << std::endl;
}
