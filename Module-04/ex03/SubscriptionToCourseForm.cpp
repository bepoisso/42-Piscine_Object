#include "SubscriptionToCourseForm.hpp"

#include <iostream>

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse), _isSubscribed(false) {
}

void SubscriptionToCourseForm::fillSubscription(Student* newStudent, Course* newCourse, const std::string& p_semester) {
	_student = newStudent;
	_course = newCourse;
	_semester = p_semester;
	setIsDataFilled(true);
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

	std::cout << "Subscription confirmed: " << _student->getName() << " -> " << _course->getName()
		<< " (" << _semester << ")" << std::endl;
}
