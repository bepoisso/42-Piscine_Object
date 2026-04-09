#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"
#include "CourseFinishedForm.hpp"

class Headmaster : public Staff
{
private:
	Secretary* 			 _secretary;
	std::vector<Form*> _formToValidate;
	bool hasReceivedForm(Form* p_form) const;
	
public:
	Headmaster(std::string p_name, Secretary *newSecretary);
	~Headmaster();

	Form*	requestForm(FormType p_formType);
	void	receiveForm(Form* p_form);
	void	submitForm(Form* p_form);
	void	signForm(Form* p_form);
	void	executeForm(Form* p_form);

};
