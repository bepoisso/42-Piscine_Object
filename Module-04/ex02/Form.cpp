#include "Form.hpp"

Form::Form(FormType p_formType) :  _formType(p_formType) {
}

Form::~Form() {
}

bool Form::getIsSigned() {
	return _isSigned;
}

void	Form::setIsSigned(bool value) {
	_isSigned = value;
}

