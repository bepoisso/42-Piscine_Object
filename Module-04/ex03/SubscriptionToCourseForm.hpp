#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"
#include "Student.hpp"
#include "Person.hpp"
#include "Course.hpp"
#include "Headmaster.hpp"

class SubscriptionToCourseForm : public Form
{
private:
	Student*	_student;
	Course*		_course;
	bool		_isSubscribed;

public:
	SubscriptionToCourseForm();

	void	fillSubscription(Student* newStudent);
	void	execute();
};
