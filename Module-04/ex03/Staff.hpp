#pragma once

#include <string>

#include "Foward.hpp"
#include "Person.hpp"

class Staff : public Person
{
public:
	Staff(const std::string& p_name);
	virtual ~Staff();

	void sign(Form* p_form);
};
