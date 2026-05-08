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
#include "Graph.hpp"
#include "Pathfinder.hpp"
#include "TrainManager.hpp"
#include "SimulationEngine.hpp"
#include "Clock.hpp"

class Simulation {
private:
	Parsing*			_parser;
	Factory*			_factory;
	Graph*				_graph;
	Pathfinder*			_pathfinder;
	SimulationEngine*	_engine;

	std::vector<Node*>		_nodesList;			// Owning: Simulation Own Nodes
	std::vector<Rail*>		_railsList;			// Owning: Simulation Own Rails
	std::vector<Train*>		_trainsList;		// Owning: Simulation Own Trains

	std::map<Train*, std::vector<Node*>>	_paths;

	long int	_deltaTime;


public:
	Simulation(long int p_dt);
	~Simulation();

	bool parseFiles(char* p_railPath, char* p_trainPath);
	bool factoryObject();
	bool pathFinder();
	bool runSimulation(long int p_startTime);
};
