#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"
#include "Student.hpp"
#include "Person.hpp"
#include "Course.hpp"

class SubscriptionToCourseForm : public Form
{
private:
	Student* _student;
	Course* _course;
	std::string _semester;
	bool		 _isSubscribed;

public:
	SubscriptionToCourseForm();
	void fillSubscription(Student* newStudent, Course* newCourse, const std::string& p_semester);
	void execute();
};
