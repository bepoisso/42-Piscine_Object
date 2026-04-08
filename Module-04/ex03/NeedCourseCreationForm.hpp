#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"

class NeedCourseCreationForm : public Form
{
private:
	std::string _courseName;
	std::string _teacherName;
	int			 _weeklyHours;
	bool		 _isCreated;

public:
	NeedCourseCreationForm();
	void fillCoursePlan(const std::string& p_courseName, const std::string& p_teacherName, int p_weeklyHours);
	void execute();
};
