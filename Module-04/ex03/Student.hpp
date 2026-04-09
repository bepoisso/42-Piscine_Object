#pragma once

#include <vector>

#include "Foward.hpp"
#include "Person.hpp"

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	Student(std::string p_name);
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);

};
