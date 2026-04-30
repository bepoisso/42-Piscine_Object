#include "Node.hpp"
#include "Rail.hpp"


Node::Node(std::string p_name, bool p_station) : APosition(p_station, true, false), _name(p_name) {
	std::cout << "[NODE] " << p_name << " created" << std::endl;
}

Node::~Node() {

}
