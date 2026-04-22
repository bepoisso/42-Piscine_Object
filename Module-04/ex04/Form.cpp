#include "Form.hpp"

Form::Form(FormType p_formType) :  _formType(p_formType) , _isSigned(false), _isDataFilled(false) {
	switch (p_formType)
	{
	case 0:
		_formName = "CourseFinished";
		break;
	case 1:
		_formName = "NeedMoreClassRoom";
		break;
	case 2:
		_formName = "NeedCourseCreation";
		break;
	case 3:
		_formName = "SubscriptionToCourse";
		break;
	
	default:
		_formName = "\033[31m[ERROR] FORM NAME \033[0m";
		break;
	}
}

Form::~Form() {
}

FormType Form::getFormType() const {
	return _formType;
}

bool Form::isComplete() const {
	return _isDataFilled;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

void	Form::setIsSigned(bool value) {
	_isSigned = value;
}

bool Form::getIsDataFilled() const {
	return _isDataFilled;
}

void	Form::setIsDataFilled(bool value) {
	_isDataFilled = value;
}

