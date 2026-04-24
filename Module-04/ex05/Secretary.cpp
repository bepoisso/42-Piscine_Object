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
			return &CourseFinishedForm();
		case NeedMoreClassRoom:
			return &NeedMoreClassRoomForm();
		case NeedCourseCreation:
			return &NeedCourseCreationForm();
		case SubscriptionToCourse:
			return &SubscriptionToCourseForm();
	}
	return NULL;
}

void Secretary::setHeadmasterMediator(Headmaster* p_headmaster) {
	_headmasterMediator = p_headmaster;
}

void Secretary::archiveForm(Form* p_form) {
	SecretarialOffice* office = static_cast<SecretarialOffice*>(getCurrentRoom());

	office->archiveForm(p_form);
}
