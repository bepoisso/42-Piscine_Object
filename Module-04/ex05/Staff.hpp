#pragma once

#include <string>

#include "Person.hpp"

class Staff : public Person
{
private:
	const unsigned int _privilege;

public:
	Staff(const std::string& p_name, const unsigned int p_priv) : Person(p_name), _privilege(p_priv) {}
	virtual ~Staff() {}

	const unsigned int 	getPrivilege() { return _privilege; }
};
