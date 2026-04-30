/**
 * @file Factory.hpp
 * @brief Factory class - Quick description
 * 
 * @details
 * This is a long comment section to describe
 * what this file do (on a multiple line).
 * 
 * @note
 * Principles:
 * - Centralize object creation in a single class.
 * - Hide instantiation logic from client code.
 * - Make it easy to add new types without changing external usage.
 * - Provide a simple interface to request a concrete object.
 * - Isolate creation details to preserve encapsulation.
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
