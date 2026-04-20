#include "Student.hpp"
#include "Person.hpp"

#include "Classroom.hpp"
#include "Course.hpp"

#include "Headmaster.hpp"
#include "SubscriptionToCourseForm.hpp"

#include <iostream>
#include <cstdlib>

Student::Student(std::string p_name) : Person(p_name), _currentScore(0), _headmasterMediator(NULL) {
}

void Student::setHeadmasterMediator(Headmaster* headmaster) {
	_headmasterMediator = headmaster;
}

void Student::attendClass(Classroom* p_classroom) {
	if (!p_classroom)
		return;

	if (getCurrentRoom())
		exitClass();

	p_classroom->enter(this);

	Course* currentCourse = p_classroom->getCurrentCourse();
	if (!currentCourse)
		return;

	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		if (*it == currentCourse)
			return;
	}
	_subscribedCourse.push_back(currentCourse);
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
	_currentScore = 0;
}

void Student::receiveLesson() {
	_currentScore += rand() % 5 + 1;
}

Course* Student::lookForClass() {
	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
		return (*it);
	}

	return NULL;

	// Form* form = _headmasterMediator->requestForm(SubscriptionToCourse);
	// SubscriptionToCourseForm* subForm = dynamic_cast<SubscriptionToCourseForm*>(form);

	// subForm->fillSubscription(this, )  //TODO remplir le formulaire d'inscription
	// TODO: envoyer le formulaire d'inscription au Headmaster
	// TODO: rajouter le cours dans la liste.
}
