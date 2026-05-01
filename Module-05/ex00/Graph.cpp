#include "Graph.hpp"


Graph::Graph(std::vector<Node*> p_nodes, std::vector<Rail*> p_rails) : _nodesList(p_nodes), _railsList(p_rails) {

}

Graph::~Graph() {

}

void Graph::createNetwork(std::vector<std::string> p_railText) {
	for (std::vector<std::string>::iterator it = p_railText.begin(); it != p_railText.end(); ++it) {
		std::vector<std::string> token = f_split(*it, " ");
		Rail* actualRail = f_getRailByTraject(_railsList, token[0], token[1]);
		Node* dep = f_getNodeByName(_nodesList, token[0]);
		Node* arr = f_getNodeByName(_nodesList, token[1]);
		if (!actualRail)
			throw std::runtime_error("can't get rail by traject");
		if (!dep || !arr)
			throw std::runtime_error("can't get node by name");
		_railsNetwork[dep].push_back(actualRail);
		_railsNetwork[arr].push_back(actualRail);
	}
	D_printNetwork();
}

void Graph::D_printNetwork() {
	std::cout << "\033[32m___DEBUG PRINT NETWORK___" << std::endl;
	for (std::map<Node*, std::vector<Rail*>>::iterator it = _railsNetwork.begin(); it != _railsNetwork.end(); ++it) {
		std::cout << "_for: " << (*it).first->getName() << "___" << std::endl;
		for (std::vector<Rail*>::iterator jt = (*it).second.begin(); jt != (*it).second.end(); ++jt) {
			std::cout << **jt << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "___DEBUG PRINT END___\033[0m" << std::endl;
}
