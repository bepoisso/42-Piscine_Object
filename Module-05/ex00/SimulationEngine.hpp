/**
 * @file SimulationEngine.hpp
 * @brief SimulationEngine class - Core simulation loop
 * 
 * @details
 * Coordinates time progression, event updates, and train updates for the
 * simulation execution.
 * 
 * @note
 * principles SRP, Encapsulation
 */

#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Forward.hpp"

#include "TrainManager.hpp"
#include "Node.hpp"
#include "Rail.hpp"
#include "Train.hpp"
#include "Time.hpp"
#include "EventManager.hpp"
#include "Config.hpp"

class SimulationEngine {
private:
	Graph*			_graph;				// non-owning: Graph are owned by Simulation
	TrainManager*	_trainManager;		// owning: SimulationEngine own TrainManager
	EventManager*	_eventManager;		// owning: SimulationEngine own EventManager

	std::map<Train*, std::vector<Node*>> _paths;

	Time				_time;
	long int			_deltaTime;
	bool				_finished;

	void init();
	void update(long int p_dt);

public:
	SimulationEngine(Graph* p_graph, std::vector<Train*> p_trains, std::map<Train*, std::vector<Node*>> p_paths, long int p_dt, long int p_startTime);
	~SimulationEngine();

	void run();
	Node* getRandCity();
	Rail* getRandRail();
};
