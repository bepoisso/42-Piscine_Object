#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class Classroom : public Room
{
private:
	static long long _nextId;
	Course* _currentCourse;                // non-owning: Course is managed elsewhere

public:
	Classroom();
	void assignCourse(Course* p_course);

	Course* getCurrentCourse() { return _currentCourse; }
};
