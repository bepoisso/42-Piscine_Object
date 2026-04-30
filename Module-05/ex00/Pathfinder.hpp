#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "Forward.hpp"

class Pathfinder {
private:
	std::vector<Node*>		_nodes;
	std::vector<Rail*>		_rails;
	std::vector<Train*>		_trains;
	std::map<Train*, std::vector<APosition*>> _optiPath;
public:
	Pathfinder(std::vector<Node*> p_nodes, std::vector<Rail*> p_rails, std::vector<Train*> p_trains);
	~Pathfinder();

	std::vector<APosition*> findOptimalPath(Train* p_train);
};
