#include "TrainManager.hpp"


TrainManager::TrainManager(Graph* p_graph, std::vector<Train*> p_trains, std::map<Train*, std::vector<Node*>> p_paths, long int p_startTime) : AClock(p_startTime), _graph(p_graph), _trains(p_trains), _paths(p_paths) {
}

TrainManager::~TrainManager() {
}

std::vector<int> TrainManager::getTrainID() {
	std::vector<int> ids;
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		ids.push_back((*it)->getID());
	return ids;
}

Train* TrainManager::getTrain(int p_id) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		if ((*it)->getID() == p_id)
			return (*it);
	}
	throw std::runtime_error("train manager: bad train ID");
}

Train* TrainManager::getTrain(std::string p_name) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		if ((*it)->getName() == p_name)
			return (*it);
	}
	throw std::runtime_error("train manager: bad train name");
}

void TrainManager::update(long int p_dt) {
	add(p_dt);
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		if (!(*it)->isFinished())
			(*it)->update(p_dt);
}

void TrainManager::init(long int p_st) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		(*it)->init(p_st);
		(*it)->setPath(_paths[*it]);
		(*it)->D_printPath();
		(*it)->setMediator(this);
	}
}

bool TrainManager::allIsFinish() {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		if (!(*it)->isFinished())
			return false;
	return true;
}
