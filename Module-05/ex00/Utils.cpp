#include "Utils.hpp"

std::vector<std::string> split(std::string p_line, const std::string& delimiter) {
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

Rail* getRailByTraject(std::vector<Rail*> p_rails, std::string p_dep, std::string p_arr) {
	for (std::vector<Rail*>::iterator it = p_rails.begin(); it != p_rails.end(); ++it) {
		if ((*it)->getprevNode()->getName() == p_dep && (*it)->getNextNode()->getName() == p_arr)
			return *it;
	}
	return NULL;
}

Node* getNodeByName(std::vector<Node*> p_nodes, std::string p_name) {
	for (std::vector<Node*>::iterator it = p_nodes.begin(); it != p_nodes.end(); ++it) {
		if ((*it)->getName() == p_name)
			return *it;
	}
	return NULL;
}
