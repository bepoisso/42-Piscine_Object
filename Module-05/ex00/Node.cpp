#include "Node.hpp"
#include "Rail.hpp"


Node::Node(std::string p_name) : _name(p_name) {
	std::cout << "[NODE] " << p_name << " created" << std::endl;
}

Node::~Node() {

}

void Node::addRail(Rail* p_rail) {
	if (!p_rail)
		throw std::runtime_error("addRail() node: " + getName() + " p_rail is null");
	for (std::vector<Rail*>::iterator it = _railsConnection.begin(); it != _railsConnection.end(); ++it)
		if (*it == p_rail)
			return;
	_railsConnection.push_back(p_rail);
}

void Node::removeRail(Rail* p_rail) {
	if (!p_rail)
		throw std::runtime_error("addRail() node: " + getName() + " p_rail is null");
	for (std::vector<Rail*>::iterator it = _railsConnection.begin(); it != _railsConnection.end(); ++it) {
		if (*it == p_rail) {
			_railsConnection.erase(it);
			return;
		}
	}
}


void Node::D_printConnection() {
	std::cout << "_for: " << getName() << "_" << std::endl;
	for (std::vector<Rail*>::iterator it = _railsConnection.begin(); it != _railsConnection.end(); ++it)
		std::cout << **it << std::endl;
	std::cout << std::endl;
}
