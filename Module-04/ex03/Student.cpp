#include "Student.hpp"
#include "Person.hpp"

Student::Student(std::string p_name) : Person(p_name) {
}

void Student::attendClass(Classroom* p_classroom) {
	getCurrentRoom();
}

void Student::exitClass() {

}

void Student::graduate(Course* p_course) {
	(void)p_course; //TODO fair la fonction student graduate()
}

