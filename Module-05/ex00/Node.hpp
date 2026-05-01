#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Forward.hpp"

#include "Position.hpp"
#include "Rail.hpp"

class Rail;

class Node : public APosition {
private:
	const std::string	_name;

public:
	Node(std::string p_name, bool p_station);
	~Node();

	const std::string getName() const { return _name; }
};
