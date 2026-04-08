#include "Staff.hpp"

#include <iostream>

#include "Form.hpp"

Staff::Staff(const std::string& p_name) : Person(p_name) {
}

Staff::~Staff() {
}

void Staff::sign(Form* p_form) {
	if (!p_form)
		return;
	p_form->setIsSigned(true);
	std::cout << getName() << " signs a form" << std::endl;
}
