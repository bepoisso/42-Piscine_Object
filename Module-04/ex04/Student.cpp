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

	for (std::vector<Course*>::iterator it = couresList.begin(); it != couresList.end(); ++it) {
		if (!isGraduateCourse(*it) && !isSubscribedCourse(*it)) {
			std::cout << "[Student] " << getName() << " request SubscriptionToCourseForm course: " << (*it)->getName() << std::endl;
			newCourseForm = dynamic_cast<SubscriptionToCourseForm*>(_headmasterMediator->requestForm(SubscriptionToCourse));
			newCourseForm->fillSubscription(this, (*it));
			_headmasterMediator->submitForm(newCourseForm);
		}
	}

	bool finish = true;
	Course* currentCourse = _subscribedCourse.empty() ? NULL : *_subscribedCourse.begin();
	for (std::vector<Course*>::iterator it = couresList.begin(); it != couresList.end(); ++it) {
		if (!isGraduateCourse((*it))) {
			finish = false;
		}
	}
	if (finish) {
		std::cout << "\033[33m[CONGRATULATION] " << getName() << " finish all courses\033[0m" << std::endl;
		return;
	}
	if (!currentCourse) {
		std::cout << "[Student] " << getName() << " is not registerd to a course" << std::endl;
		return;
	}
	if (!currentCourse->getClassroom()) {
		std::cout << "\033[31m[ERROR] Course has no classroom course: " << currentCourse->getName() << "\033[0m" << std::endl;
		return;
	}
	currentCourse->getClassroom()->enter(this);
	std::cout << "[Student] " << getName() << " enter in class " << currentCourse->getClassroom()->getID() << " for " << currentCourse->getName() << "'s course by " << currentCourse->getResponsable()->getName() << std::endl;
}

void Student::exitClass() {
	Room* currentRoom = getCurrentRoom();
	if (!currentRoom)
		return;
	currentRoom->exit(this);
	std::cout << "[Student] " << getName() << " exit the classroom no " << currentRoom->getID() << std::endl;
}

void Student::graduate(Course* p_course) {
	if (!p_course)
		return;

	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if (*it == p_course) {
			_subscribedCourse.erase(it);
			_scoreCourse.erase(p_course);
			addGraduateCourse(p_course);
			std::cout << "[Student] " << getName() << " graduated from " << p_course->getName() << std::endl;
			return;
		}
	}
}

void Student::receiveLesson(Course* p_course) {
	int temp = rand() % 50 + 1;
	_scoreCourse[p_course] += temp;
	std::cout << "[Student] " << getName() << " Recive lesson for " << p_course->getName() << "'s course, with score " <<
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
	if (event != RingBell)
		return;
	_isOnBreak = !_isOnBreak;
	if (_isOnBreak)
		exitClass();
}
