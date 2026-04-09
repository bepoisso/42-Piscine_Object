#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"

class Course
{
private:
	std::string _name;
	Professor* _responsable;               // non-owning: Professor is managed elsewhere
	std::vector<Student*> _students;       // non-owning: Students are managed elsewhere
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
public:
	Course(std::string p_name);
	void assign(Professor* p_professor);
	void subscribe(Student* p_student);

	std::string getName() { return _name; }
	Professor* getResponsable() { return _responsable; }
	void setResponsable(Professor* newReponsable) { _responsable = newReponsable; }
	int getNumberOfClassToGraduate() const { return _numberOfClassToGraduate; }
	int getMaximumNumberOfStudent() const { return _maximumNumberOfStudent; }
	void setNumberOfClassToGraduate(int value) { _numberOfClassToGraduate = value; }
	void setMaximumNumberOfStudent(int value) { _maximumNumberOfStudent = value; }
};
