#include "Course.hpp"

Course::Course(std::string p_name) : _name(p_name){
}

void Course::assign(Professor* p_professor) {
	_responsable = p_professor;
}

void Course::subscribe(Student* p_student) {
	_students.push_back(p_student);
}
