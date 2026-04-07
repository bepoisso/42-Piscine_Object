#pragma once

#include <iostream>
#include "Foward.hpp"

class Form
{
private:
	FormType 	_formType;
	bool		_isSigned;

public:
	Form(FormType p_formType);
	virtual ~Form();
	virtual void execute() = 0;

	bool	getIsSigned();
	void	setIsSigned(bool value);
};
