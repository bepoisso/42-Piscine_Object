#include "Headmaster.hpp"
#include "Form.hpp"

Headmaster::~Headmaster() {
}

Headmaster::Headmaster(std::string p_name) : Staff(p_name) {
}

void Headmaster::receiveForm(Form* p_form) {
	_formToValidate.push_back(p_form);
}

void	Headmaster::signeForm(Form* p_form) {
	p_form->setIsSigned(true);
}
