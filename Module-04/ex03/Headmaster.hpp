#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	std::vector<Course*> _courses;
	std::vector<Classroom*> _classrooms;
	Secretary* _secretary;

	bool hasReceivedForm(Form* p_form) const;

public:
	Headmaster(const std::string& p_name);
	~Headmaster();

	void setSecretary(Secretary* p_secretary);

	void receiveForm(Form* p_form);
	void signForm(Form* p_form);
	void executeForm(Form* p_form);

	void createCourse(const std::string& p_courseName);
	void teachCourse(Professor* p_professor);
	void attendCourse(Student* p_student);
	void graduateStudent(Student* p_student, Course* p_course);
	void requestClassroom(Professor* p_professor);

	std::vector<Course*>& getCourses();
	std::vector<Classroom*>& getClassrooms();
	Course* findAvailableCourse() const;
	Classroom* findFreeClassroom() const;
};
