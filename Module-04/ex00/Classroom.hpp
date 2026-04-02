#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class Classroom : public Room
{
private:
	Course* _currentCourse;                // non-owning: Course is managed elsewhere

public:
	Classroom();
	void assignCourse(Course* p_course);
};
