#include "Secretary.hpp"

#include "CourseFinishedForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "SubscriptionToCourseForm.hpp"

Secretary::Secretary(std::string p_name) : Staff(p_name) {
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

void Secretary::fillForm(Form* p_form, const FormPayload& p_payload) {
	if (!p_form)
		return;

	switch (p_form->getFormType())
	{
		case CourseFinished: {
			CourseFinishedForm* courseFinishedForm = dynamic_cast<CourseFinishedForm*>(p_form);
			if (courseFinishedForm)
				courseFinishedForm->fillCourseResult(p_payload.student, p_payload.course, p_payload.number);
			break;
		}
		case NeedMoreClassRoom: {
			NeedMoreClassRoomForm* needMoreClassRoomForm = dynamic_cast<NeedMoreClassRoomForm*>(p_form);
			if (needMoreClassRoomForm)
				needMoreClassRoomForm->fillRequest(p_payload.professor, p_payload.text1, p_payload.number);
			break;
		}
		case NeedCourseCreation: {
			NeedCourseCreationForm* needCourseCreationForm = dynamic_cast<NeedCourseCreationForm*>(p_form);
			if (needCourseCreationForm)
				needCourseCreationForm->fillCoursePlan(p_payload.course, p_payload.professor, p_payload.number);
			break;
		}
		case SubscriptionToCourse: {
			SubscriptionToCourseForm* subscriptionToCourseForm = dynamic_cast<SubscriptionToCourseForm*>(p_form);
			if (subscriptionToCourseForm)
				subscriptionToCourseForm->fillSubscription(p_payload.student, p_payload.course, p_payload.text3);
			break;
		}
	}
}
