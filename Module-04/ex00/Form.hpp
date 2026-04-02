#pragma once

#include "Foward.hpp"

class Form
{
private:
	FormType _formType;

public:
	Form(FormType p_formType);
	virtual ~Form();
	virtual void execute() = 0;
};
