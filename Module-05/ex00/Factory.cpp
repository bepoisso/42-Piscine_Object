#include "Factory.hpp"


Factory::Factory(){
}

Factory::~Factory(){
}

void Factory::createNodes(const std::vector<std::string> p_nodes) {
	std::string line;
	for (std::vector<std::string>::const_iterator it = p_nodes.begin(); it != p_nodes.end(); ++it) {
		line = *it;
		_nodes.push_back(new Node(line));
	}
}

void Factory::createRails(const std::vector<std::string> p_rails) {
	for (std::vector<std::string>::const_iterator it = p_rails.begin(); it != p_rails.end(); ++it) {
		std::string line = *it;
		std::vector<std::string> token = _split(line, " ");
		Node* prev = _getNodeByName(token[0]);
		Node* next = _getNodeByName(token[1]);
		float lenght = std::stof(token[2]);
		float speed = std::stof(token[3]);
		// TODO : mettre un check
		_rails.push_back(new Rail(prev, next, lenght, speed));
	}
}

void Factory::creatTrains(const std::vector<std::string> p_trains) {
	for (std::vector<std::string>::const_iterator it = p_trains.begin(); it != p_trains.end(); ++it) {
		std::string line = *it;
		std::vector<std::string> token = _split(line, " ");
		std::string name = token[0];
		int weight = std::stoi(token[1]);
		float friction = std::stof(token[2]);
		float acceleration = std::stof(token[3]);
		float brake = std::stof(token[4]);
		Node* dep = _getNodeByName(token[5]);
		Node* arr = _getNodeByName(token[6]);
		std::string depTime = token[7];
		std::string stopTime = token[8];
		// TODO: mettre un check
		_trains.push_back(new Train(name, weight, friction, acceleration, brake, dep, arr, depTime, stopTime));
	}
}



std::vector<std::string> Factory::_split(std::string p_line, const std::string& delimiter) {
	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;
	while ((pos = p_line.find(delimiter)) != std::string::npos) {
		token = p_line.substr(0, pos);
		tokens.push_back(token);
		p_line.erase(0, pos + delimiter.length());
	}
	tokens.push_back(p_line);

	return tokens;
}

Node* Factory::_getNodeByName(std::string p_name) {
	for (std::vector<Node*>::iterator it = _nodes.begin(); it != _nodes.end(); ++it) {
		if (p_name == (*it)->getName())
			return *it;
	}
	return NULL;
}

