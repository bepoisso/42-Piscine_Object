#pragma once

#include "Foward.hpp"
#include "Person.hpp"

class Staff : public Person
{
private:

public:
	Staff(std::string p_name);
	void sign(Form* p_form);
};
