#pragma once

#include "Foward.hpp"
#include "Staff.hpp"
#include "Headmaster.hpp"
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "Staff.hpp"

class Professor : public Staff
{
private:
	Course* _currentCourse;

public:
	Professor(std::string p_name);
	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();

	void needGraduateStudent(Headmaster* headmaster, Student* student);
};
