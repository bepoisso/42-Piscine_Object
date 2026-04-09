#pragma once

#include <string>

class Student;
class Course;
class Professor;

enum FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

enum Event
{
	RingBell
};

struct FormPayload
{
	Student* 	  student;
	Course* 	  course;
	Professor* professor;
	std::string text1;
	std::string text2;
	std::string text3;
	int			 number;

	FormPayload(Student* p_student = 0, Course* p_course = 0, Professor* p_professor = 0,
		const std::string& p_text1 = "", const std::string& p_text2 = "", const std::string& p_text3 = "", int p_number = 0)
		: student(p_student), course(p_course), professor(p_professor), text1(p_text1), text2(p_text2), text3(p_text3), number(p_number) {}
};
