#pragma once

enum FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

enum Event
{
	RingBell
};

struct FormPayload
{
	std::string text1;
	std::string text2;
	std::string text3;
	int			 number;

	FormPayload(const std::string& p_text1 = "", const std::string& p_text2 = "", const std::string& p_text3 = "", int p_number = 0)
		: text1(p_text1), text2(p_text2), text3(p_text3), number(p_number) {}
};
