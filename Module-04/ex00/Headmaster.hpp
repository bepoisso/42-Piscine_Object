#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"

class Headmaster : public Staff
{
private:
	// Non-owning references: Headmaster validates but does not own these forms.
	std::vector<Form*> _formToValidate;    // non-owning: Forms are managed by SecretarialOffice
	
public:
	Headmaster(std::string p_name);
	~Headmaster();
	void receiveForm(Form* p_form);
};
