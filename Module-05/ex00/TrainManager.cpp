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
		if (!(*it)->isFinished()) {
			(*it)->update(p_dt);
			printTrainState((*it));
		}
}

void TrainManager::init(long int p_st) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		(*it)->init(p_st);
		(*it)->setMediator(this);
		(*it)->setPath(_paths[*it]);
		(*it)->D_printPath();
	}
}

bool TrainManager::allIsFinish() {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		if (!(*it)->isFinished())
			return false;
	return true;
}

void TrainManager::printTrainState(Train* t) {
	if (!t)
		throw std::runtime_error("trainmanager: train is nill can't print train state");
	// if (((getCurrentTime() % Time("00h01").getTime()) != Time(0)))
	// 	return;
	if (getCurrentTime() < t->getDepartureTime() || t->isFinished())
		return;

	double rTot = t->getCurrentRail()->getLenght() / 1000;
	double dRem = t->getTotalRemaining() / 1000;
	int position = t->getPos();
	std::cout << "[" << Time(getCurrentTime() - t->getDepartureTime()) << "] - [";
	std::cout << std::setw(9) << std::right << t->getPath(t->getPathIndex() - 1)->getName().substr(0, 9)
		<< "][" << std::setw(9) << std::right << t->getPath(t->getPathIndex())->getName().substr(0, 9);
	std::cout << "] - ["<< f_formatDistance(dRem) << "km] - [";
	switch (t->getCurrentState())
	{
	case ACCELERATING:
		std::cout << "Speed up";
		break;
	case BRAKING:
		std::cout << " Braking";
		break;
	case MAINTAINING:
		std::cout << "Maintain";
		break;
	case STOPPED:
		std::cout << " Stopped";
		break;
	default:
	std::cout << "error";
		break;
	}
	std::cout << "] - [" << f_formatDistance(t->getCurrentVelocity() * 3.6) << "km/h] - ";
	for (int i = 0; i <= rTot; ++i) {
		if (i == position)
			std::cout << "[x]";
		//TODO: rajouter les autres train si ils bloc
		else
			std::cout << "[ ]";
	}
	std::cout << std::endl;
}
