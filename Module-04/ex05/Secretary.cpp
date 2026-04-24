#include "Secretary.hpp"

#include "CourseFinishedForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "SubscriptionToCourseForm.hpp"

Secretary::Secretary(std::string p_name) : Staff(p_name, 2) {
}

Form* Secretary::createForm(FormType p_formType) {
	switch (p_formType)
	{
		case CourseFinished:
			return new CourseFinishedForm();
		case NeedMoreClassRoom:
			return new NeedMoreClassRoomForm();
		case NeedCourseCreation:
			return new NeedCourseCreationForm();
		case SubscriptionToCourse:
			return new SubscriptionToCourseForm();
	}
	return NULL;
}

void Secretary::setHeadmasterMediator(Headmaster* p_headmaster) {
	_headmasterMediator = p_headmaster;
}
