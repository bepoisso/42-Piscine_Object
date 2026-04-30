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

	std::map<Node*, std::vector<Rail*>> _railsNetwork;		// non-owning: Network are owned by Simulation

public:
	Graph(std::vector<Node*> p_nodes, std::vector<Rail*> p_rails);
	~Graph();

	void createNetwork(const std::vector<std::string> p_railText);
	std::map<Node*, std::vector<Rail*>> getRailsNetwork() const { return _railsNetwork; }

	// TODO: (debug) retirer avant mis en prod
	void D_printNetwork();
};
