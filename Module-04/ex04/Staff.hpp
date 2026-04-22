#pragma once

#include <string>

#include "Person.hpp"

class Staff : public Person
{
private:

public:
	Staff(const std::string& p_name) : Person(p_name) {}
	virtual ~Staff() {}
};
