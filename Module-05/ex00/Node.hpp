#pragma once

#include <string>

#include "Foward.hpp"


class Node{
private:
	const std::string _name;

public:
	Node(std::string p_name);
	~Node();

	const std::string getName() const { return _name; }
};
