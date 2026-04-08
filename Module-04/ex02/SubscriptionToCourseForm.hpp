#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"

class SubscriptionToCourseForm : public Form
{
private:
	std::string _studentName;
	std::string _courseName;
	std::string _semester;
	bool		 _isSubscribed;

public:
	SubscriptionToCourseForm();
	void fillSubscription(const std::string& p_studentName, const std::string& p_courseName, const std::string& p_semester);
	void execute();
};
