#include "Course.hpp"

#include <iostream>

#include "Classroom.hpp"
#include "Professor.hpp"
#include "Student.hpp"

Course::Course(const std::string& p_name, int p_numberOfClassToGraduate, int p_maximumNumberOfStudent)
	: _name(p_name), _responsable(0), _classroom(0), _numberOfClassToGraduate(p_numberOfClassToGraduate), _maximumNumberOfStudent(p_maximumNumberOfStudent) {
}

const std::string& Course::getName() const {
	return _name;
}

Professor* Course::getProfessor() const {
	return _responsable;
}

Classroom* Course::getClassroom() const {
	return _classroom;
}

int Course::getStudentCount() const {
	return static_cast<int>(_students.size());
}

int Course::getRequiredClasses() const {
	return _numberOfClassToGraduate;
}

void Course::assign(Professor* p_professor) {
	_responsable = p_professor;
}

bool Course::subscribe(Student* p_student) {
	if (!p_student || hasStudent(p_student))
		return false;
	if (static_cast<int>(_students.size()) >= _maximumNumberOfStudent)
		return false;
	_students.push_back(StudentProgress(p_student));
	return true;
}

void Course::attachClassroom(Classroom* p_classroom) {
	_classroom = p_classroom;
}

void Course::teachSession() {
	for (std::vector<StudentProgress>::iterator it = _students.begin(); it != _students.end(); ++it)
		it->attendedClasses += 1;
	std::cout << "Course " << _name << ": one class session completed for " << _students.size() << " student(s)." << std::endl;
}

bool Course::hasStudent(Student* p_student) const {
	return (findProgress(p_student) != 0);
}

bool Course::canGraduate(Student* p_student) const {
	const StudentProgress* progress = findProgress(p_student);
	if (!progress)
		return false;
	return progress->attendedClasses >= _numberOfClassToGraduate;
}

int Course::attendedClassesOf(Student* p_student) const {
	const StudentProgress* progress = findProgress(p_student);
	if (!progress)
		return 0;
	return progress->attendedClasses;
}

Course::StudentProgress* Course::findProgress(Student* p_student) {
	for (std::vector<StudentProgress>::iterator it = _students.begin(); it != _students.end(); ++it) {
		if (it->student == p_student)
			return &(*it);
	}
	return 0;
}

const Course::StudentProgress* Course::findProgress(Student* p_student) const {
	for (std::vector<StudentProgress>::const_iterator it = _students.begin(); it != _students.end(); ++it) {
		if (it->student == p_student)
			return &(*it);
	}
	return 0;
}
