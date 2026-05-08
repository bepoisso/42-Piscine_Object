#include "Node.hpp"

Node::Node(std::string p_name, bool p_station) : _name(p_name), _isStation(p_station), _delay(0) {
	std::cout << "[NODE] " << p_name << " created, ";
	if (_isStation)
		std::cout << "is a station";
	else
		std::cout << "is not a station";
	std::cout << std::endl;
}

Node::~Node() {
	
}
