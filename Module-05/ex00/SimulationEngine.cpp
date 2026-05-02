#include "SimulationEngine.hpp"


SimulationEngine::SimulationEngine(TrainManager* p_tManage, Graph* p_graph, std::map<Train*, std::vector<Node*>> p_paths, long int p_dt, long int p_startTime) :
	_trainManager(p_tManage), _graph(p_graph), _paths(p_paths), _time(Time(p_startTime)), _deltaTime(p_dt), _finished(false) {

}

SimulationEngine::~SimulationEngine() {

}

void SimulationEngine::init() {
	_trainsId = _trainManager->getTrainID();
	_trainManager->init(_time.getTime());
}

void SimulationEngine::run() {
	init();
	while (!_finished) {

		update(_deltaTime);
		_finished = _trainManager->allIsFinish();
		_time = _time + _deltaTime;
	}
}

void SimulationEngine::update(long int p_dt) {
	_trainManager->update(p_dt);
	// _event->update(p-dt);
}
