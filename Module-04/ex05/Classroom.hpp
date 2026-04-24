#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class Classroom : public Room
{
private:
	static long long _nextId;
	Course* _currentCourse;				// non-owning: owning by School

public:
	Classroom();
	void assignCourse(Course* p_course);

	void enterMessage();
	Course* getCurrentCourse() { return _currentCourse; }
};
