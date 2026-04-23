#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"
#include "Headmaster.hpp"

class Secretary : public Staff
{
private:
	Headmaster* _headmasterMediator;

public:
	Secretary(std::string p_name);
	std::string printHeader() { return "[Secretary] "; }
	Form* createForm(FormType p_formType);
	void setHeadmasterMediator(Headmaster* p_headmaster);
};
