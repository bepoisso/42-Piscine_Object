#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Forward.hpp"

#include "Rail.hpp"

class Rail;

class Node {
private:
	const std::string	_name;
	const bool			_isStation;

public:
	Node(std::string p_name, bool p_station);
	~Node();

	const std::string getName() const { return _name; }
	bool isStation() const { return _isStation; }
};
