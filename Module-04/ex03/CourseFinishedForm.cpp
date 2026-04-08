#include "CourseFinishedForm.hpp"
#include <iostream>

CourseFinishedForm::CourseFinishedForm() : Form(CourseFinished), _finalGrade(0), _isCompleted(false) {
}

void CourseFinishedForm::fillCourseResult(const std::string& p_studentName, const std::string& p_courseName, int p_finalGrade) {
	_studentName = p_studentName;
	_courseName = p_courseName;
	_finalGrade = p_finalGrade;
	setIsDataFilled(true);
}

void CourseFinishedForm::execute() {
	if (!getIsSigned()) {
		std::cout << "CourseFinishedForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!getIsDataFilled()) {
		std::cout << "CourseFinishedForm execution refused: missing course result data" << std::endl;
		return;
	}
	_isCompleted = true;
	std::cout << "Course validation done: " << _studentName << " finished " << _courseName
		<< " with grade " << _finalGrade << std::endl;
}
