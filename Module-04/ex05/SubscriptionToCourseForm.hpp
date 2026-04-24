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
	Student*	_student;			// non-owning: owning by School
	Course*		_course;			// non-owning: owning by School
	bool		_isSubscribed;

public:
	SubscriptionToCourseForm();
	void	fillSubscription(Student* newStudent, Course* p_course);
	void	execute();
};
