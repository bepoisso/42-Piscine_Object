#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"

class Secretary : public Staff
{
private:

public:
	Secretary(std::string p_name);
	std::string printHeader() { return "[Secretary] "; }
	Form* createForm(FormType p_formType);
};
