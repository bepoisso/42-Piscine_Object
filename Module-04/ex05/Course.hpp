#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Classroom.hpp"

class Course
{
private:
	std::string _name;
	Professor* _responsable;				// non-owning: owning by School
	std::vector<Student*> _students;		// non-owning: owning by School
	Classroom* _classroom;					// non-owning: owning by School

	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;

public:
	Course(std::string p_name);
	void assign(Professor* p_professor);
	void subscribe(Student* p_student);
	void unsubscribe(Student* p_student);

	std::string getName() { return _name; }
	Professor* getResponsable() { return _responsable; }
	void setResponsable(Professor* newReponsable) { _responsable = newReponsable; }
	int getNumberOfClassToGraduate() const { return _numberOfClassToGraduate; }
	int getMaximumNumberOfStudent() const { return _maximumNumberOfStudent; }
	int getNumberOfStudent();
	void setNumberOfClassToGraduate(int value) { _numberOfClassToGraduate = value; }
	void setMaximumNumberOfStudent(int value) { _maximumNumberOfStudent = value; }
	std::vector<Student*> getStudents() { return _students; }
	void setClassroom(Classroom* p_classroom);
	Classroom* getClassroom() { return _classroom; }
	bool isStudentSubscribed();
};
