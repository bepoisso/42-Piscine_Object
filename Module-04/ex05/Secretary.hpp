#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"
#include "Headmaster.hpp"
#include "SecretarialOffice.hpp"

class Secretary : public Staff
{
private:
	Headmaster* _headmasterMediator;			// non-owning: owning by School

public:
	Secretary(std::string p_name);
	std::string printHeader() { return "[Secretary]   "; }
	Form* createForm(FormType p_formType);
	void setHeadmasterMediator(Headmaster* p_headmaster);
};
