#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class Classroom : public Room
{
private:
	Course* _currentCourse;

public:
	Classroom();

	void assignCourse(Course* p_course);
	void clearCourse();
	Course* getCurrentCourse() const;
	bool isFree() const;
};
