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
};
