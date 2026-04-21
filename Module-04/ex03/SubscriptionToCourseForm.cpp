#include "SubscriptionToCourseForm.hpp"

#include <iostream>

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse), _isSubscribed(false) {
}

void SubscriptionToCourseForm::fillSubscription(Student* newStudent) {
	_student = newStudent;
	Headmaster *mediator = _student->getheadmasterMediator();
	_course = mediator->giveNewCourseForStudent(_student);
	if (_student && _course)
		setIsDataFilled(true);
	else
		setIsDataFilled(false);
}

void SubscriptionToCourseForm::execute() {
	if (!getIsSigned()) {
		std::cout << "SubscriptionToCourseForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!getIsDataFilled()) {
		std::cout << "SubscriptionToCourseForm execution refused: missing subscription data" << std::endl;
		return;
	}
	_isSubscribed = true;
	
	_student->addSubscribedCourse(_course);
	_course->addStudent(_student);

	std::cout << "Subscription confirmed: " << _student->getName() << " -> " << _course->getName() << std::endl;
}
