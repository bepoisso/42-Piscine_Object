#include "NeedCourseCreationForm.hpp"

#include <iostream>

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation), _weeklyHours(0), _isCreated(false) {
}

void NeedCourseCreationForm::fillCoursePlan(const std::string& p_courseName, const std::string& p_teacherName, int p_weeklyHours) {
	_courseName = p_courseName;
	_teacherName = p_teacherName;
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
	std::cout << "Course created: " << _courseName << " assigned to " << _teacherName
		<< " (" << _weeklyHours << "h/week)" << std::endl;
}
