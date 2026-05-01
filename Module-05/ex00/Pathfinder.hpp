#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

#include "Forward.hpp"

#include "Graph.hpp"
#include "Rail.hpp"
#include "Node.hpp"
#include "Train.hpp"

class Pathfinder {
private:
	Graph* _graph;

	std::vector<Node*> getNeighbors(Node* p_node) const;
	const std::vector<Rail*>& getRails(Node* p_node) const;
	Node* getOtherNode(Rail* p_rail, Node* p_current) const;
	double calculateCost(Rail* p_rail, Train* p_train);
	std::vector<Node*> reconstructPath(std::map<Node*, Node*>& p_prev, Node* p_start, Node* p_end) const;
public:
	Pathfinder(Graph* p_graph);
	~Pathfinder();

	std::vector<Node*> findOptimalPath(Node* p_start, Node* p_end, Train* p_train);

	// TODO: a retirer avant mis en prod
	void D_printPath(std::vector<Node*> p_nodes) { std::cout << "\033[32m___DEBUG PRINT PATH___\nFor: " << p_nodes.front()->getName() << " <--> " << p_nodes.back()->getName() << std::endl; for (std::vector<Node*>::iterator i = p_nodes.begin();i != p_nodes.end();++i) std::cout << (*i)->getName() << std::endl; std::cout << "___DEBUG PRINT END___\033[0m" << std::endl;}
};
