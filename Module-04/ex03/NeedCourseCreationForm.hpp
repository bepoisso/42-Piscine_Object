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
	std::string	 _name;
	Professor*	 _professor;
	int			 _weeklyHours;

public:
	NeedCourseCreationForm();
	void fillCoursePlan(std::string newName, Professor* newProfessor, int p_weeklyHours);
	void execute();

	std::string getName() { return _name; }
	Professor* getProfessor() { return _professor; }
};
