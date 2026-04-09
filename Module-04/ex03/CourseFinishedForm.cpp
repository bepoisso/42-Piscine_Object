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

bool CourseFinishedForm::isComplete() const {
	if (!getIsDataFilled())
		return false;
	if (!_student || !_course)
		return false;
	return _finalGrade > _course->getNumberOfClassToGraduate();
}

void CourseFinishedForm::execute() {
	if (!getIsSigned()) {
		std::cout << "CourseFinishedForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!isComplete()) {
		std::cout << "CourseFinishedForm execution refused: invalid grade or missing course result data" << std::endl;
		return;
	}
	_isCompleted = true;
	std::cout << "Course validation done: " << _student->getName() << " finished " << _course->getName()
		<< " with grade " << _finalGrade << std::endl;
	_student->graduate(_course);
}
