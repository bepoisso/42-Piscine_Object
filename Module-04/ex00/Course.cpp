#include "Course.hpp"

Course::Course(std::string p_name) : _name(p_name){
}

void Course::assign(Professor* p_professor) {
	(void)p_professor;
}

void Course::subscribe(Student* p_student) {
	(void)p_student;
}
