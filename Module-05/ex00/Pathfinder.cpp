#include "Pathfinder.hpp"

Pathfinder::Pathfinder(Graph* p_graph) : _graph(p_graph) {

}

Pathfinder::~Pathfinder() {

}

std::vector<Node*> Pathfinder::findOptimalPath(Node* p_start, Node* p_end, Train* p_train) {
	if (!p_start)
		throw std::runtime_error("node start is nill can't find optimal path");
	if (!p_end)
		throw std::runtime_error("node end is nill can't find optimal path");

	std::vector<Node*>				nodesList = _graph->getNodes();
	std::map<Node*, double>			distances;
	std::map<Node*, Node*>			previous;
	std::vector<Node*>				toVisit;
	std::vector<Node*>				neighborsList;

	Node*							current;
	Node*							minNode;
	Rail*							bestRail;
	
	// INITIALIZATION
	toVisit.push_back(p_start);

	for (std::vector<Node*>::iterator it = nodesList.begin(); it != nodesList.end(); ++it)
		distances[*it] = std::numeric_limits<double>::infinity();

	distances[p_start] = 0;

	// DIJKSTRA LOOP
	while (!toVisit.empty()) {
		// find node with lowest distance
		minNode = toVisit[0];

		for (std::vector<Node*>::iterator it = toVisit.begin(); it != toVisit.end(); ++it) {
			if (distances[*it] < distances[minNode])
				minNode = *it;
		}

		current = minNode;
		
		std::vector<Node*>::iterator eraseIt = std::find(toVisit.begin(), toVisit.end(), current);
		
		if (eraseIt != toVisit.end())
			toVisit.erase(eraseIt);

		if (current == p_end)
			break;

		// get neighbors of current
		neighborsList = getNeighbors(current);
		std::vector<Rail*> railsConnection = getRails(current);
		
		// explore all neighbors
		for (std::vector<Node*>::iterator it = neighborsList.begin(); it != neighborsList.end(); ++it) {
			Node* neighbor = *it;
			double bestCost = std::numeric_limits<double>::infinity();
			bestRail = NULL;
	
			// Find sahred rail beetween current and neighbor
			for (std::vector<Rail*>::iterator rt = railsConnection.begin(); rt != railsConnection.end(); ++rt) {
				if (getOtherNode(*rt, current) == neighbor) {
					double cost = calculateCost(*rt, p_train);
					if (cost < bestCost) {
						bestCost = cost;
						bestRail = *rt;
					}
				}
			}
			// RELAXATION (Dijkstra's relaxation step)
			if (bestRail) {
				double newCost = distances[current] + bestCost;

				if (newCost < distances[neighbor]) {
					distances[neighbor] = newCost;
					previous[neighbor] = current;
					toVisit.push_back(neighbor);
				}
			}
		}
	}

	return reconstructPath(previous, p_start, p_end);
}

std::vector<Node*> Pathfinder::getNeighbors(Node* p_node) const {
	std::vector<Node*> neighbors;
	std::vector<Rail*> connectedRails;

	if (!p_node)
		throw std::runtime_error("node is nill can't get neighbors nodes");

	connectedRails = getRails(p_node);
	
	for (std::vector<Rail*>::iterator it = connectedRails.begin(); it != connectedRails.end(); ++it)
		neighbors.push_back(getOtherNode(*it, p_node));
	
	return neighbors;
}

const std::vector<Rail*>& Pathfinder::getRails(Node* p_node) const {
	const auto& railsNetwork = _graph->getRailsNetwork();

	if (!p_node)
		throw std::runtime_error("node is nill can't get rails");

	if (railsNetwork.find(p_node) == railsNetwork.end())
		throw std::runtime_error("node is not inside the rails network");

	return railsNetwork.at(p_node);
}

Node* Pathfinder::getOtherNode(Rail* p_rail, Node* p_current) const {
	if (!p_rail)
		throw std::runtime_error("rail is nill can't get other node");

	if (!p_current)
		throw std::runtime_error("node is nill can't get other node");

	if (p_rail->getPrevNode() != p_current && p_rail->getNextNode() != p_current)
		throw std::runtime_error("node: \""  + p_current->getName() + "\" is not connected to rail: \""
			+ p_rail->getPrevNode()->getName()+ " <--> " + p_rail->getNextNode()->getName() + "\"");

	if (p_rail->getPrevNode() == p_current)
		return p_rail->getNextNode();

	return p_rail->getPrevNode();
}

double Pathfinder::calculateCost(Rail* p_rail, Train* p_train) {
	if (!p_rail)
		throw std::runtime_error("rail is nill can't calculate cost");

	double acc = (p_train->getTractionMax() - p_train->getFrictionForce()) / p_train->getWeight();

	if (acc <= 0)
		return std::numeric_limits<double>::infinity();
	
	double vMax = p_rail->getSpeedMax();
	double dist = p_rail->getLenght();
	double tAcc = vMax / acc;
	double dAcc = 0.5 * acc * tAcc * tAcc;

	if (dAcc >= dist) {
		return sqrt(2 * dist / acc);
	}
	else {
		double d_const = dist - dAcc;
		double t_const = d_const / vMax;
		return tAcc + t_const;
	}
}

std::vector<Node*> Pathfinder::reconstructPath(std::map<Node*, Node*>& p_prev, Node* p_start, Node* p_end) const {
	if (!p_start)
		throw std::runtime_error("node is nill can't reconstrust path");

	if (!p_end)
		throw std::runtime_error("node is nill can't reconstrust path");

	std::vector<Node*> path;
	Node* current = p_end;

	while (current != p_start) {
		path.push_back(current);

		std::map<Node*, Node*>::iterator it = p_prev.find(current);

		if (it == p_prev.end() || !it->second)
			throw std::runtime_error("invalid path: broken predecessor chain");

		current = it->second;
	}
	path.push_back(current);
	std::reverse(path.begin(), path.end());
	
	return path;
}

