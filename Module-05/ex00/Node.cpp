#include "Node.hpp"

Node::Node(std::string p_name, bool p_station) : _name(p_name), _isStation(p_station) {
	std::cout << "[NODE] " << p_name << " created" << std::endl;
}

Node::~Node() {
	
}
