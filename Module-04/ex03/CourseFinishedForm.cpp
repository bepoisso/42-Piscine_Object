#include "CourseFinishedForm.hpp"
#include <iostream>

CourseFinishedForm::CourseFinishedForm() : Form(CourseFinished), _finalGrade(0), _isCompleted(false) {
}

void CourseFinishedForm::fillCourseResult(Student* newStudent, Course* newCourse, int p_finalGrade) {
	_student = newStudent;
	_course = newCourse;
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
	std::cout << "Course validation done: " << _student->getName() << " finished " << _course->getName()
		<< " with grade " << _finalGrade << std::endl;
	_student->exitClass();
}
