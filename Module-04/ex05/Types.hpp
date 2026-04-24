#pragma once

#include <string>
#include <map>

class Student;
class Course;
class Professor;
class School;

enum FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

enum Event
{
	RingBell,
	LunchTime,
	CoursesFinish,
};
