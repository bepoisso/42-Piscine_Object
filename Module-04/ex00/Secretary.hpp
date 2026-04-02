#pragma once

#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"

class Secretary : public Staff
{
private:

public:
	Secretary(std::string p_name);
	Form* createForm(FormType p_formType);
};
