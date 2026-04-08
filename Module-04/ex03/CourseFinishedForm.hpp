#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"

class CourseFinishedForm : public Form
{
private:
	std::string _studentName;
	std::string _courseName;
	int			 _finalGrade;
	bool		 _isCompleted;

public:
	CourseFinishedForm();
	void fillCourseResult(const std::string& p_studentName, const std::string& p_courseName, int p_finalGrade);
	void execute();
};
