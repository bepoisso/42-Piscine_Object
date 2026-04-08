#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	bool hasReceivedForm(Form* p_form) const;
	
public:
	Headmaster(std::string p_name);
	~Headmaster();

	void	receiveForm(Form* p_form);
	void	signForm(Form* p_form);
	void	executeForm(Form* p_form);
};
