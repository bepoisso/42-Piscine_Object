#include "SimulationEngine.hpp"


SimulationEngine::SimulationEngine(Graph* p_graph, std::vector<Train*> p_trains, std::map<Train*, std::vector<Node*>> p_paths, long int p_dt, long int p_startTime) :
	_graph(p_graph), _trainManager(nullptr), _eventManager(nullptr),_paths(p_paths), _time(Time(p_startTime)), _deltaTime(p_dt), _finished(false)
{
	_trainManager = new TrainManager(_graph, p_trains, _paths, p_startTime);
	_eventManager = new EventManager(this);
}

SimulationEngine::~SimulationEngine() {
	delete _trainManager;
	delete _eventManager;
}

void SimulationEngine::init() {
	_trainManager->init(_time.getTime());
}

void SimulationEngine::run() {
	init();
	while (!_finished) {
		if (EVENTS) {
			int rand = std::rand() % 1000;		// 1000 = 0.1% of chance on each ticks
			if (rand == 0)
				_eventManager->generateRandomEvent();
		}

		update(_deltaTime);
		_finished = _trainManager->allIsFinish();
		_time = _time + _deltaTime;
	}
}

void SimulationEngine::update(long int p_dt) {
	_eventManager->update(p_dt);
	_trainManager->update(p_dt);
}

Node* SimulationEngine::getRandCity() {
	std::vector<Node*> nodes = _graph->getNodes();
	std::vector<Node*> citys;

	for (std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
		if ((*it)->isStation())
			citys.push_back(*it);
	
	size_t rand = std::rand() % citys.size();
	Node* n = citys[rand];

	if (!n)
		throw std::runtime_error(" node (City) is nill can't get random city");

	return citys[rand];
}

Rail* SimulationEngine::getRandRail() {
	std::vector<Rail*> rails = _graph->getRails();
	size_t rand = std::rand() % rails.size();
	Rail* r = rails[rand];

	if (!r)
		throw std::runtime_error(" rail is nill can't get random rail");

	return r;
}
