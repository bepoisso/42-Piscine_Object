#include "Staff.hpp"

Staff::Staff(std::string p_name) : Person(p_name) {}

void Staff::sign(Form* p_form) {
	(void)p_form;
}
