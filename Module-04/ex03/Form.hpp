#pragma once

#include <iostream>
#include "Foward.hpp"

class Form
{
private:
	FormType 	_formType;
	bool		_isSigned;
	bool		_isDataFilled;

public:
	Form(FormType p_formType);
	virtual ~Form();
	virtual void execute() = 0;
	virtual bool isComplete() const;

	FormType getFormType() const;
	bool	getIsSigned() const;
	void	setIsSigned(bool value);
	bool	getIsDataFilled() const;
	void	setIsDataFilled(bool value);
};
