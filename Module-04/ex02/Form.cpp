#include "Form.hpp"

Form::Form(FormType p_formType) :  _formType(p_formType) , _isSigned(false), _isDataFilled(false) {
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

