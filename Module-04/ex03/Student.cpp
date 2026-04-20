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
		// Demander un formulaire d'inscription au cours

		currentCourse->addStudent(this);
	}
	
	setCurrentRoom(currentCourse->getClassroom());
}

void Student::exitClass() {
	Room* currentRoom = getCurrentRoom();
	if (!currentRoom)
		return;
	currentRoom->exit(this);
}

void Student::graduate(Course* p_course) {
	if (!p_course)
		return;

	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if (*it == p_course) {
			_subscribedCourse.erase(it);
			std::cout << "Student " << getName() << " graduated from " << p_course->getName() << std::endl;
			return;
		}
	}
	_scoreCourse.erase(p_course);
}

void Student::receiveLesson(Course* p_course) {
	_scoreCourse[p_course] += rand() % 5 + 1;
}
