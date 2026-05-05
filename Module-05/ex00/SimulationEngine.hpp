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

class SimulationEngine {
private:
	TrainManager*	_trainManager;
	Graph*			_graph;
	std::map<Train*, std::vector<Node*>> _paths;

	std::vector<int>	_trainsId;
	Time				_time;
	long int			_deltaTime;
	bool				_finished;

	void init();
	void update(long int p_dt);

public:
	SimulationEngine(TrainManager* p_tManage, Graph* p_graph, std::map<Train*, std::vector<Node*>> p_paths, long int p_dt, long int p_startTime);
	~SimulationEngine();

	void run();
};
