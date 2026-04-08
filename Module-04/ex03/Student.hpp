#pragma once

#include <vector>

#include "Foward.hpp"
#include "Person.hpp"

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	Student(const std::string& p_name);

	void addCourse(Course* p_course);
	bool hasAnyCourse() const;
	bool isSubscribedTo(Course* p_course) const;
	Course* firstCourse() const;

	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};
