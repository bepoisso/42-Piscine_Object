#include "Factory.hpp"


Factory::Factory(){
}

Factory::~Factory(){
}

void Factory::createNodes(const std::vector<std::string> p_nodes) {
	std::string line;
	for (std::vector<std::string>::const_iterator it = p_nodes.begin(); it != p_nodes.end(); ++it) {
		line = *it;
		if (line.empty())
			throw std::runtime_error("fail to create node");
		if (line.find("City") == 0)
			_nodes.push_back(new Node(line, true));
		else if (line.find("Rail") == 0)
			_nodes.push_back(new Node(line, false));
		else
			throw std::runtime_error("Node " + line + " is not a City or a Rail Node");
	}
}

void Factory::createRails(const std::vector<std::string> p_rails) {
	for (std::vector<std::string>::const_iterator it = p_rails.begin(); it != p_rails.end(); ++it) {
		std::string line = *it;
		std::vector<std::string> token = split(line, " ");
		if (token[0].empty() || token[1].empty() || token[2].empty() || token[3].empty())
			throw std::runtime_error("fail to create rails");
		Node* prev = _getNodeByName(token[0]);
		Node* next = _getNodeByName(token[1]);
		float lenght = std::stof(token[2]);
		float speed = std::stof(token[3]);
		// TODO : mettre un check des valeurs
		_rails.push_back(new Rail(prev, next, lenght, speed));
		prev->addRail(_rails.back());
		next->addRail(_rails.back());
	}
}

void Factory::createTrains(const std::vector<std::string> p_trains) {
	for (std::vector<std::string>::const_iterator it = p_trains.begin(); it != p_trains.end(); ++it) {
		std::string line = *it;
		std::vector<std::string> token = split(line, " ");
		if (token[0].empty() || token[1].empty() || token[2].empty() || token[3].empty() || token[4].empty() || token[5].empty() || token[6].empty() || token[7].empty() || token[8].empty())
			throw std::runtime_error("fail to create trains");
		std::string name = token[0];
		int weight = std::stoi(token[1]);
		float friction = std::stof(token[2]);
		float acceleration = std::stof(token[3]);
		float brake = std::stof(token[4]);
		Node* dep = _getNodeByName(token[5]);
		Node* arr = _getNodeByName(token[6]);
		std::string depTime = token[7];
		std::string stopTime = token[8];
		// TODO: mettre un check des valeurs
		_trains.push_back(new Train(name, weight, friction, acceleration, brake, dep, arr, depTime, stopTime));
	}
}

Node* Factory::_getNodeByName(std::string p_name) {
	for (std::vector<Node*>::iterator it = _nodes.begin(); it != _nodes.end(); ++it) {
		if (p_name == (*it)->getName())
			return *it;
	}
	return NULL;
}

// DEBUG

void Factory::D_printNodesConnections() {
	std::cout << "\033[32m___DEBUG RAIL CONNECTION___" << std::endl;
	for (std::vector<Node*>::iterator it = _nodes.begin(); it != _nodes.end(); ++it)
		(*it)->D_printConnection();
	std::cout << "___DEBUG RAIL CONNECTION END___\033[0m" << std::endl;
}
