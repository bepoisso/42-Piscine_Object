#include "Headmaster.hpp"

#include <iostream>

#include "Form.hpp"
#include "Secretary.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "CourseFinishedForm.hpp"

Headmaster::Headmaster(const std::string& p_name) : Staff(p_name), _secretary(0) {
}

Headmaster::~Headmaster() {
	for (std::vector<Course*>::iterator it = _courses.begin(); it != _courses.end(); ++it) {
		delete *it;
	}
	_courses.clear();

	for (std::vector<Classroom*>::iterator it = _classrooms.begin(); it != _classrooms.end(); ++it) {
		delete *it;
	}
	_classrooms.clear();
}

void Headmaster::setSecretary(Secretary* p_secretary) {
	_secretary = p_secretary;
}

void Headmaster::receiveForm(Form* p_form) {
	_formToValidate.push_back(p_form);
}

bool Headmaster::hasReceivedForm(Form* p_form) const {
	for (std::vector<Form*>::const_iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it) {
		if (*it == p_form)
			return true;
	}
	return false;
}

void Headmaster::signForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << "Headmaster refused to sign: form was not received" << std::endl;
		return;
	}
	if (!p_form->isComplete()) {
		std::cout << "Headmaster refused to sign: mandatory form data is missing" << std::endl;
		return;
	}
	p_form->setIsSigned(true);
	std::cout << getName() << " signs the form." << std::endl;
}

void Headmaster::executeForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << "Headmaster refused to execute: form was not received" << std::endl;
		return;
	}
	p_form->execute();
}

void Headmaster::createCourse(const std::string& p_courseName) {
	Course* newCourse = new Course(p_courseName);
	_courses.push_back(newCourse);
	std::cout << "Headmaster created course: " << p_courseName << std::endl;
}

void Headmaster::teachCourse(Professor* p_professor) {
	if (!p_professor)
		return;

	if (p_professor->getCurrentCourse())
		return;

	if (_courses.empty()) {
		std::cout << p_professor->getName() << " has no course to teach." << std::endl;
		return;
	}

	Course* availableCourse = findAvailableCourse();
	if (!availableCourse) {
		std::cout << p_professor->getName() << " has no available course to teach." << std::endl;
		return;
	}

	p_professor->assignCourse(availableCourse);
}

void Headmaster::attendCourse(Student* p_student) {
	if (!p_student)
		return;

	if (p_student->hasAnyCourse())
		return;

	if (_courses.empty()) {
		std::cout << p_student->getName() << " has no course to join." << std::endl;
		return;
	}

	Course* availableCourse = findAvailableCourse();
	if (!availableCourse) {
		std::cout << p_student->getName() << " has no available course to join." << std::endl;
		return;
	}

	p_student->addCourse(availableCourse);
}

void Headmaster::graduateStudent(Student* p_student, Course* p_course) {
	if (!p_student || !p_course)
		return;

	if (!p_course->canGraduate(p_student)) {
		std::cout << p_student->getName() << " cannot graduate from " << p_course->getName() 
			<< " (attended: " << p_course->attendedClassesOf(p_student) 
			<< "/" << p_course->getRequiredClasses() << " classes)" << std::endl;
		return;
	}

	p_student->graduate(p_course);
}

void Headmaster::requestClassroom(Professor* p_professor) {
	if (!p_professor || !p_professor->getCurrentCourse())
		return;

	Classroom* freeRoom = findFreeClassroom();
	if (freeRoom) {
		p_professor->getCurrentCourse()->attachClassroom(freeRoom);
		std::cout << "Found an available classroom for " << p_professor->getName() << std::endl;
		return;
	}

	std::cout << "No free classroom. Creating a new one for " << p_professor->getName() << std::endl;
	Classroom* newRoom = new Classroom();
	_classrooms.push_back(newRoom);
	if (p_professor->getCurrentCourse())
		p_professor->getCurrentCourse()->attachClassroom(newRoom);
}

std::vector<Course*>& Headmaster::getCourses() {
	return _courses;
}

std::vector<Classroom*>& Headmaster::getClassrooms() {
	return _classrooms;
}

Course* Headmaster::findAvailableCourse() const {
	for (std::vector<Course*>::const_iterator it = _courses.begin(); it != _courses.end(); ++it) {
		// Course must have space available; professor can be assigned later
		if ((*it)->getStudentCount() < 30)
			return *it;
	}
	return 0;
}


Classroom* Headmaster::findFreeClassroom() const {
	for (std::vector<Classroom*>::const_iterator it = _classrooms.begin(); it != _classrooms.end(); ++it) {
		if ((*it)->isFree())
			return *it;
	}
	return 0;
}
