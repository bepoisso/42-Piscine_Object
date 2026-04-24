#include "SubscriptionToCourseForm.hpp"

#include <iostream>

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse), _isSubscribed(false) {
}

void SubscriptionToCourseForm::fillSubscription(Student* newStudent, Course* p_course) {
	_student = newStudent;
	_course = p_course;
	if (_student && _course && _course->getNumberOfStudent() < _course->getMaximumNumberOfStudent())
		setIsDataFilled(true);
	else
		setIsDataFilled(false);
}

void SubscriptionToCourseForm::execute() {
	if (_course->getNumberOfStudent() >= _course->getMaximumNumberOfStudent()) {
		std::cout << "SubscriptionToCourseForm execution refused: course is full" << std::endl;
		return;
	}
	if (!getIsSigned()) {
		std::cout << "SubscriptionToCourseForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!getIsDataFilled()) {
		std::cout << "SubscriptionToCourseForm execution refused: missing subscription data" << std::endl;
		return;
	}
	if (_course->getNumberOfStudent() >= _course->getMaximumNumberOfStudent()) {
		std::cout << "SubscriptionToCourseForm execution refused: course is full" << std::endl;
		return;
	}
	_isSubscribed = true;
	_student->addSubscribedCourse(_course);
	_course->subscribe(_student);

	std::cout << "Subscription confirmed: " << _student->getName() << " -> " << _course->getName() << std::endl;
}
