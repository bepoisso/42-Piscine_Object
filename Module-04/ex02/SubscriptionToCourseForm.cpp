#include "SubscriptionToCourseForm.hpp"

#include <iostream>

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse), _isSubscribed(false) {
}

void SubscriptionToCourseForm::fillSubscription(const std::string& p_studentName, const std::string& p_courseName, const std::string& p_semester) {
	_studentName = p_studentName;
	_courseName = p_courseName;
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
	std::cout << "Subscription confirmed: " << _studentName << " -> " << _courseName
		<< " (" << _semester << ")" << std::endl;
}
