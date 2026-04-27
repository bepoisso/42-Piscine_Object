#include "Student.hpp"
#include "Person.hpp"

#include "Classroom.hpp"
#include "Course.hpp"

#include "Headmaster.hpp"
#include "SubscriptionToCourseForm.hpp"

#include <iostream>
#include <cstdlib>

Student::Student(std::string p_name) : Person(p_name), _subscribedCourse(), _scoreCourse(), _graduateCourse(), _headmasterMediator(NULL) {
}

void Student::setHeadmasterMediator(Headmaster* headmaster) {
	_headmasterMediator = headmaster;
	if (_headmasterMediator)
		_headmasterMediator->subscribeBell(this);
}

void Student::attendClass() {
	std::vector<Course*> couresList = _headmasterMediator->getCourseList();
	SubscriptionToCourseForm* newCourseForm;
	_isOnBreak = false;
	bool flag = true;
	std::cout << printHeader()<< getName() << " request subscription to all cours" << std::endl;
	for (std::vector<Course*>::iterator it = couresList.begin(); it != couresList.end(); ++it) {
		if (!isGraduateCourse(*it)) { 
			flag = false;
			if (!isSubscribedCourse(*it)) {
				newCourseForm = dynamic_cast<SubscriptionToCourseForm*>(_headmasterMediator->requestForm(SubscriptionToCourse));
				newCourseForm->fillSubscription(this, (*it));
				_headmasterMediator->submitForm(newCourseForm);
			}
		}
	}
	if (flag == true) {
		std::cout << printHeader() << getName() << " is graduate from all courses !!!" << std::endl;
		_headmasterMediator->getCourtyard()->enter(this);
		return;
	}
	Course* currentCourse = _subscribedCourse.empty() ? NULL : *_subscribedCourse.begin();
	if (!currentCourse) {
		std::cout << printHeader() << getName() << " is not registerd to a course" << std::endl;
		_headmasterMediator->getCourtyard()->enter(this);
		return;
	}
	if (!currentCourse->getClassroom()) {
		std::cout << "\033[31m[ERROR] Course has no classroom course: " << currentCourse->getName() << "\033[0m" << std::endl;
		return;
	}
	currentCourse->getClassroom()->enter(this);
}

void Student::graduate(Course* p_course) {
	if (!p_course)
		return;

	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if (*it == p_course) {
			_subscribedCourse.erase(it);
			_scoreCourse.erase(p_course);
			addGraduateCourse(p_course);
			std::cout << printHeader() << getName() << " graduated from " << p_course->getName() << std::endl;
			return;
		}
	}
}

void Student::receiveLesson(Course* p_course) {
	int temp = rand() % 50 + 1;
	_scoreCourse[p_course] += temp;
	std::cout << printHeader() << getName() << " Recive lesson for " << p_course->getName() << "'s course, with score " <<
		_scoreCourse[p_course] << "/" << p_course->getNumberOfClassToGraduate() << std::endl; 
}

bool Student::isGraduateCourse(Course* p_course) {
	for(std::vector<Course*>::iterator it = _graduateCourse.begin(); it != _graduateCourse.end(); ++it) {
		if ((*it) == p_course)
			return true;
	}
	return false;
}

bool Student::isSubscribedCourse(Course* p_course) {
	for(std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if ((*it) == p_course)
			return true;
	}
	return false;
}

void Student::onBell(Event event) {
	if (event == RingBell) {
		_isOnBreak = !_isOnBreak;
		if (_isOnBreak) {
			if (getCurrentRoom() != _headmasterMediator->getCourtyard()) {
				safeExit();
				_headmasterMediator->getCourtyard()->enter(this);
			}
		} else {
			safeExit();
			attendClass();
		}
	}
	else if (event == LunchTime) {
		_isOnBreak = true;
		safeExit();
		_headmasterMediator->getCanteen()->enter(this);
		std::cout << printHeader() << getName() << " eating a lot in the cafeteria" << std::endl; 
	} else if (event == CoursesFinish) {
		_isOnBreak = true;
		safeExit();
	} else {
		std::cout << "[ERROR] " << getName() << " received a bad event" << std::endl;
	}
}
