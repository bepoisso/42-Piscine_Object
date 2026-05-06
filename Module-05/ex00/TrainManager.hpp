#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

#include "Forward.hpp"
#include "Train.hpp"
#include "Clock.hpp"
#include "Graph.hpp"

class TrainManager : public AClock {
private:
	Graph*									_graph;
	std::vector<Train*>						_trains;
	std::map<Train*, std::vector<Node*>>	_paths;
	std::map<Train*, std::ofstream*>		_trainFiles;

public:
	TrainManager(Graph* p_graph, std::vector<Train*> p_trains, std::map<Train*, std::vector<Node*>> p_paths, long int p_startTime);
	~TrainManager();

	std::vector<int> getTrainID();
	Train* getTrain(int p_id);
	Train* getTrain(std::string p_name);
	Graph* getGraph() { return _graph; }
	void	setPaths(std::map<Train*, std::vector<Node*>> p_paths) { _paths = p_paths; }
	bool	allIsFinish();

	void update(long int p_dt);
	void init(long int p_st);
	void writeOutputHeader(Train* t);
	void writeTrainState(Train* t);
	Time getEstimateTravelTime(Train* t);
};
