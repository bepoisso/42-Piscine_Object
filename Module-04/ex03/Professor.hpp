#pragma once

#include "Foward.hpp"
#include "Staff.hpp"
#include "Headmaster.hpp"
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "Staff.hpp"

class Professor : public Staff
{
private:
	Course* _currentCourse;
	Headmaster* _headmasterMediator;

public:
	Professor(std::string p_name);
	void setHeadmasterMediator(Headmaster* headmaster);
	Headmaster* getheadmasterMediator() { return _headmasterMediator; }
	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();

	void needGraduateStudent(Student* student);
	void needNewCourse();
	void needMoreClassRoom();
	Course* getCourse() { return _currentCourse; }
	void setCourse(Course* p_course) { _currentCourse = p_course; }
};
