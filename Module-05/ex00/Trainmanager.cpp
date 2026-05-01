#include "TrainManager.hpp"


TrainManager::TrainManager(std::vector<Train*> p_trains, long int p_startTime) : AClock(p_startTime), _trains(p_trains) {
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

void TrainManager::update(long int p_dt) {
	add(p_dt);
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		(*it)->update(p_dt);
}

void TrainManager::init(long int p_st) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		(*it)->init(p_st);
}
