/**
 * @file Simulation.hpp
 * @brief Simulation class - Main facade of the program
 * 
 * @details
 * This class serves as the facade pattern implementation, providing a unified
 * and simplified interface to the complex subsystems of the program.
 * It respects the SOLID principles, particularly the Single Responsibility Principle,
 * by delegating specific tasks to appropriate classes while maintaining a clean
 * and cohesive public API.
 * 
 * @note
 * principles SOLID
 * design_pattern Facade
 */

#pragma once

#include "Forward.hpp"

#include "Parsing.hpp"
#include "Factory.hpp"

class Simulation {
private:
	Parsing*	_parser;
	Factory*	_factory;

	std::vector<Node*>		_nodesList;			// Owning: Simulation Owning Nodes
	std::vector<Rail*>		_railsList;			// Owning: Simulation Owning Rails
	std::vector<Train*>		_trainsList;		// Owning: Simulation Owning Trains


public:
	Simulation();
	~Simulation();

	void parseFiles(char* p_railPath, char* p_trainPath);
	void factoryObject();
};
