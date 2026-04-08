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
	Form* createForm(FormType p_formType);
	void fillForm(Form* p_form, const FormPayload& p_payload);
};
