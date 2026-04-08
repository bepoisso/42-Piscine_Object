#include "Student.hpp"

#include <iostream>

#include "Classroom.hpp"
#include "Course.hpp"

Student::Student(const std::string& p_name) : Person(p_name) {
}

void Student::addCourse(Course* p_course) {
	if (!p_course || isSubscribedTo(p_course))
		return;
	_subscribedCourse.push_back(p_course);
	p_course->subscribe(this);
	std::cout << getName() << " subscribed to " << p_course->getName() << std::endl;
}

bool Student::hasAnyCourse() const {
	return !_subscribedCourse.empty();
}

bool Student::isSubscribedTo(Course* p_course) const {
	for (std::vector<Course*>::const_iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if (*it == p_course)
			return true;
	}
	return false;
}

Course* Student::firstCourse() const {
	if (_subscribedCourse.empty())
		return 0;
	return _subscribedCourse[0];
}

void Student::attendClass(Classroom* p_classroom) {
	if (!p_classroom || !p_classroom->getCurrentCourse()) {
		std::cout << getName() << " cannot attend class: no active course in classroom." << std::endl;
		return;
	}
	std::cout << getName() << " attends class for " << p_classroom->getCurrentCourse()->getName() << std::endl;
}

void Student::exitClass() {
	std::cout << getName() << " exits class." << std::endl;
}

void Student::graduate(Course* p_course) {
	if (!p_course)
		return;
	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if (*it == p_course) {
			_subscribedCourse.erase(it);
			break;
		}
	}
	std::cout << getName() << " graduated from " << p_course->getName() << std::endl;
}
