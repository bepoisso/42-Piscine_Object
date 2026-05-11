/**
 * @file Factory.hpp
 * @brief Factory class - Create domain objects
 * 
 * @details
 * Centralizes creation of nodes, rails, and trains from parsed input data.
 * 
 * @note
 * principles SRP, Encapsulation
 * design_pattern Factory
 */

#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "Utils.hpp"
#include "Forward.hpp"

#include "Node.hpp"
#include "Rail.hpp"
#include "Train.hpp"

class Factory{
private:
	std::vector<Node*>		_nodes;
	std::vector<Rail*>		_rails;
	std::vector<Train*>		_trains;

public:
	Factory();
	~Factory();

	void createNodes(const std::vector<std::string> p_nodes);
	void createRails(const std::vector<std::string> p_rails);
	void createTrains(const std::vector<std::string> p_trains);

	const std::vector<Node*>	getNodes() const { return _nodes; }
	const std::vector<Rail*>	getRails() const { return _rails; }
	const std::vector<Train*>	getTrains() const { return _trains; }
};
