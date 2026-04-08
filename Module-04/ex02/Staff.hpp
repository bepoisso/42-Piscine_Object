#pragma once

#include <string>

class Staff
{
private:
	std::string _name;

public:
	Staff(const std::string& p_name) : _name(p_name) {}
	virtual ~Staff() {}
};
