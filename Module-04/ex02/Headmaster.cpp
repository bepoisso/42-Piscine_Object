#include "Headmaster.hpp"
#include "Form.hpp"

#include <iostream>

Headmaster::~Headmaster() {
}

Headmaster::Headmaster(std::string p_name) : Staff(p_name) {
}

void Headmaster::receiveForm(Form* p_form) {
	_formToValidate.push_back(p_form);
}

bool Headmaster::hasReceivedForm(Form* p_form) const {
	for (std::vector<Form*>::const_iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it) {
		if (*it == p_form)
			return true;
	}
	return false;
}

void	Headmaster::signForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << "Headmaster refused to sign: form was not received" << std::endl;
		return;
	}
	if (!p_form->isComplete()) {
		std::cout << "Headmaster refused to sign: mandatory form data is missing" << std::endl;
		return;
	}
	p_form->setIsSigned(true);
}

void	Headmaster::executeForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << "Headmaster refused to execute: form was not received" << std::endl;
		return;
	}
	p_form->execute();
}
