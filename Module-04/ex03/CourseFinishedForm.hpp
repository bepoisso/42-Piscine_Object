#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Person.hpp"

class CourseFinishedForm : public Form
{
private:
	Student*		_student;
	Course*			_course;
	int				_finalGrade;
	bool			_isCompleted;

public:
	CourseFinishedForm();
	void fillCourseResult(Student* newStudent, Course* newCourse, int p_finalGrade);
	void execute();
};
