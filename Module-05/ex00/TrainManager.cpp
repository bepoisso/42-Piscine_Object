#include "TrainManager.hpp"


TrainManager::TrainManager(Graph* p_graph, std::vector<Train*> p_trains, std::map<Train*, std::vector<Node*>> p_paths, long int p_startTime) : AClock(p_startTime), _graph(p_graph), _trains(p_trains), _paths(p_paths) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		std::string path = "./outputs/" + (*it)->getName() + "_" + (*it)->getDepartureTime().getTimeToS() + ".result";
		_trainFiles[(*it)] = new std::ofstream(path);
		if (!_trainFiles[*it]->is_open())
			throw std::runtime_error("trainmanager: fail to open output train files: " + path);
	}
}

TrainManager::~TrainManager() {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		if (_trainFiles.find(*it) == _trainFiles.end())
			continue;
		if (_trainFiles[*it]->is_open())
			_trainFiles[*it]->close();
		delete _trainFiles[*it];
	}
	_trainFiles.clear();
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
			writeTrainState((*it));
		}
}

void TrainManager::init(long int p_st) {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		(*it)->init(p_st);
		(*it)->setMediator(this);
		(*it)->setPath(_paths[*it]);
		writeOutputHeader(*it);
	}
}

bool TrainManager::allIsFinish() {
	for (std::vector<Train*>::iterator it = _trains.begin(); it != _trains.end(); ++it)
		if (!(*it)->isFinished())
			return false;
	return true;
}

void TrainManager::writeOutputHeader(Train* t) {
	if (!t)
		throw std::runtime_error("trainmanager: train is nill can't write output train header");
	if (_trainFiles.find(t) == _trainFiles.end() || !_trainFiles.find(t)->second)
		throw std::runtime_error("trainmanager: train \"" + t->getName() + "\"'s output file is nill, can't write train header");
	std::ofstream& out = *_trainFiles[t];
	out << "Train: " << t->getName() << std::endl;
	out << "Final travel time: " << getEstimateTravelTime(t) << std::endl << std::endl;
}

Time TrainManager::getEstimateTravelTime(Train* t) {
	if (!t)
		throw std::runtime_error("trainmanager: train is nill can't get estimate travel time");
	long double tTot = 0;

	std::vector<Node*> path = _paths[t];
	double mass = t->getWeight();
	double brake = t->getBrakeMax() / mass;
	double acc = t->getTractionMax() / mass;
	double oldV = 0;

	if (acc == 0 || brake == 0)
		throw std::runtime_error("acceleration or brake is equal to 0, can't get estimate travel time");

	for (std::vector<Node*>::iterator it = path.begin(); it + 1 != path.end(); ++it) {
		Rail* r = _graph->getRail(*it, *(it + 1));
		if (!r)
			throw std::runtime_error("trainmanager: rail is nill can't get estimate travel time");
		double d = r->getLenght();
		double vMax = r->getSpeedMax();
		double nextVMax = vMax;
		if (it + 2 != path.end()) {
			Rail* rNext = _graph->getRail(*(it + 1), *(it + 2));
			nextVMax = rNext->getSpeedMax();
		}
		double vTarget = std::min(vMax, nextVMax);
		if ((*(it + 1))->isStation()) {
			vTarget = 0;
			tTot += t->getStopTime().getTime();
		}
		double dAcc = std::max(0.0, ((vMax * vMax) - (oldV * oldV)) / (acc * 2));
		double dBrake = ((vMax * vMax) - (vTarget * vTarget)) / (brake * 2);
		double tAcc = std::max(0.0, ((vMax - oldV) / acc));
		double tBrake = std::max(0.0, (vMax - vTarget) / brake);
		if (dAcc + dBrake < d) {
			double tCruise = (d - dAcc - dBrake) / vMax;
			tTot += tAcc + tCruise + tBrake;
		}
		else {
			double vPeak = sqrt( ((2 * acc * brake * d) + (brake * oldV * oldV) + (acc * vTarget * vTarget)) / (acc + brake) );
			tAcc = std::max(0.0, (vPeak - oldV) / acc);
			tBrake = std::max(0.0, (vPeak - vTarget) / brake);
			tTot += tAcc + tBrake;
		}
		oldV = vTarget;
	}
	return Time(tTot);
}

void TrainManager::writeTrainState(Train* t) {
	if (!t)
		throw std::runtime_error("trainmanager: train is nill can't write train state");
	if (_trainFiles.find(t) == _trainFiles.end() || !_trainFiles.find(t)->second)
		throw std::runtime_error("trainmanager: train \"" + t->getName() + "\"'s output file is nill, can't write train state");
	
	if (((getCurrentTime() % Time("00h01").getTime()) != Time(0)))
		return;
	if (getCurrentTime() < t->getDepartureTime() || t->isFinished())
		return;

	std::ofstream& out = *_trainFiles[t];

	double rTot = t->getCurrentRail()->getLenght() / 1000;
	double dRem = t->getTotalRemaining() / 1000;
	int position = t->getPos();
	out << "[" << Time(getCurrentTime() - t->getDepartureTime()) << "] - [";
	out << std::setw(9) << std::right << t->getPath(t->getPathIndex() - 1)->getName().substr(0, 9)
		<< "][" << std::setw(9) << std::right << t->getPath(t->getPathIndex())->getName().substr(0, 9);
	out << "] - ["<< f_formatDistance(dRem) << "km] - [";
	switch (t->getCurrentState())
	{
	case ACCELERATING:
		out << "Speed up";
		break;
	case BRAKING:
		out << " Braking";
		break;
	case MAINTAINING:
		out << "Maintain";
		break;
	case STOPPED:
		out << " Stopped";
		break;
	default:
	out << "error";
		break;
	}
	out << "] - ";
	for (int i = 0; i <= rTot; ++i) {
		if (i == position)
			out << "[x]";
		//TODO: rajouter les autres train si ils bloc
		else
			out << "[ ]";
	}
	out << std::endl;
}
