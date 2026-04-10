#pragma once

#include <vector>

#include "Foward.hpp"
#include "Person.hpp"

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;
	int _currentScore;
	Headmaster* _headmasterMediator;

public:
	Student(std::string p_name);
	void setHeadmasterMediator(Headmaster* headmaster);
	Headmaster* getheadmasterMediator() { return _headmasterMediator; }
	int getCurrentScore() { return _currentScore; }
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
	void receiveLesson();
	Course* lookForClass();

};
