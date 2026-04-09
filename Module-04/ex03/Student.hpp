#pragma once

#include <vector>

#include "Foward.hpp"
#include "Person.hpp"

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;
	int _currentScore;

public:
	Student(std::string p_name);
	int getCurrentScore() { return _currentScore; }
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
	void receiveLesson();

};
