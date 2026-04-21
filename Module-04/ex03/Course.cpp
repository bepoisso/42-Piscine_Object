#include "Course.hpp"

#include <iostream>

Course::Course(std::string p_name)
	: _name(p_name), _responsable(NULL), _numberOfClassToGraduate(10), _maximumNumberOfStudent(30) {
}

void Course::assign(Professor* p_professor) {
	_responsable = p_professor;
}

void Course::subscribe(Student* p_student) {
	if (!p_student)
		return;
	for (std::vector<Student*>::iterator it = _students.begin(); it != _students.end(); ++it) {
		if (*it == p_student)
			return;
	}
	if ((int)_students.size() >= _maximumNumberOfStudent) {
		std::cout << "Cannot subscribe student: course " << _name << " is full" << std::endl;
		return;
	}
	_students.push_back(p_student);
}

void Course::setClassroom(Classroom* p_classroom) {
	_classroom = p_classroom;
}

void Course::unsubscribe(Student* p_student) {
	for (std::vector<Student*>::iterator it = _students.begin(); it != _students.end(); ++it) {
		if (*it == p_student) {
			_students.erase(it);
			return;
		}
	}
}


