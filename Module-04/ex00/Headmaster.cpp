#include "Headmaster.hpp"

Headmaster::~Headmaster() {
}

Headmaster::Headmaster(std::string p_name) : Staff(p_name) {
}

void Headmaster::receiveForm(Form* p_form) {
	_formToValidate.push_back(p_form);
}
