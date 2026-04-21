#include "Student.hpp"
#include "Person.hpp"

#include "Classroom.hpp"
#include "Course.hpp"

#include "Headmaster.hpp"
#include "SubscriptionToCourseForm.hpp"

#include <iostream>
#include <cstdlib>

Student::Student(std::string p_name) : Person(p_name), _headmasterMediator(NULL) {
}

void Student::setHeadmasterMediator(Headmaster* headmaster) {
	_headmasterMediator = headmaster;
}

void Student::attendClass() {
	Course* currentCourse = _subscribedCourse.empty() ? NULL : *_subscribedCourse.begin();
	if (currentCourse == NULL) {
		std::cout << "[Student] " << getName() << " request SubscriptionToCourseForm" << std::endl;
		SubscriptionToCourseForm* newCourseForm = dynamic_cast<SubscriptionToCourseForm*>(_headmasterMediator->requestForm(SubscriptionToCourse));
		newCourseForm->fillSubscription(this);
		_headmasterMediator->submitForm(newCourseForm);
	}
	currentCourse = _subscribedCourse.empty() ? NULL : *_subscribedCourse.begin();
	if (currentCourse == NULL) {
		std::cout << "[Student] " << getName() << " as finish all course!" << std::endl;
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
	int temp = rand() % 5 + 1;
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
