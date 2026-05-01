#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "Forward.hpp"
#include "Utils.hpp"

#include "Node.hpp"
#include "Rail.hpp"

class Graph
{
private:
	std::vector<Node*>		_nodesList;					// non-owning: Node are owned by Simulation
	std::vector<Rail*>		_railsList;					// non-owning: Rail are owned by Simulation

	std::map<Node*, std::vector<Rail*>> _railsNetwork;		// owning: Graph own RailsNetwork; do not delete : Simulation own Rail & Node

public:
	Graph(std::vector<Node*> p_nodes, std::vector<Rail*> p_rails);
	~Graph();

	void createNetwork(const std::vector<std::string> p_railText);
	const std::map<Node*, std::vector<Rail*>>& getRailsNetwork() const { return _railsNetwork; }
	std::vector<Node*> getNodes() const { return _nodesList; }
	std::vector<Rail*> getRails() const { return _railsList; }

	// TODO: (debug) retirer avant mis en prod
	void D_printNetwork();
};
