#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"

class Course
{
private:
	struct StudentProgress {
		Student* student;
		int attendedClasses;
		StudentProgress(Student* p_student) : student(p_student), attendedClasses(0) {}
	};

	std::string _name;
	Professor* _responsable;
	Classroom* _classroom;
	std::vector<StudentProgress> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;

	StudentProgress* findProgress(Student* p_student);
	const StudentProgress* findProgress(Student* p_student) const;

public:
	Course(const std::string& p_name, int p_numberOfClassToGraduate = 3, int p_maximumNumberOfStudent = 30);

	const std::string& getName() const;
	Professor* getProfessor() const;
	Classroom* getClassroom() const;
	int getStudentCount() const;
	int getRequiredClasses() const;

	void assign(Professor* p_professor);
	bool subscribe(Student* p_student);
	void attachClassroom(Classroom* p_classroom);
	void teachSession();
	bool hasStudent(Student* p_student) const;
	bool canGraduate(Student* p_student) const;
	int attendedClassesOf(Student* p_student) const;
};
