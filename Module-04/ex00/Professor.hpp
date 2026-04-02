#pragma once

#include "Foward.hpp"
#include "Staff.hpp"

class Professor : public Staff
{
private:
	Course* _currentCourse;                // non-owning: Course is managed elsewhere

public:
	Professor(std::string p_name);
	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();
};
