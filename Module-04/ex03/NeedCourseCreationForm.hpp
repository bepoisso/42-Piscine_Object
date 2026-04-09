#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include "Person.hpp"
#include "Staff.hpp"

class NeedCourseCreationForm : public Form
{
private:
	Course*		_course;
	Professor*	_professor;
	int			 _weeklyHours;
	bool		 _isCreated;

public:
	NeedCourseCreationForm();
	void fillCoursePlan(Course* newCourse, Professor* newProfessor, int p_weeklyHours);
	void execute();

	Course* getCourse() { return _course; }
	Professor* getProfessor() { return _professor; }
};
