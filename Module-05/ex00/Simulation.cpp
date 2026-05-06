#include "Simulation.hpp"

Simulation::Simulation(long int p_dt) :
	_parser(nullptr), _factory(nullptr), _graph(nullptr), _pathfinder(nullptr), _trainManager(nullptr), _engine(nullptr), _deltaTime(p_dt) {
	
}

Simulation::~Simulation() {
	delete _parser;
	delete _factory;
	delete _graph;
	delete _pathfinder;
	delete _trainManager;
	delete _engine;
	for (std::vector<Node*>::iterator it = _nodesList.begin(); it != _nodesList.end(); ++it)
		delete *it;
	_nodesList.clear();
	for (std::vector<Rail*>::iterator it = _railsList.begin(); it != _railsList.end(); ++it)
		delete *it;
	_railsList.clear();
	for (std::vector<Train*>::iterator it = _trainsList.begin(); it != _trainsList.end(); ++it)
		delete *it;
	_trainsList.clear();
}

bool Simulation::parseFiles(char* p_railPath, char* p_trainPath) {
	try {
		std::cout << "===========================" << std::endl;
		std::cout << "      Parsing process      " << std::endl;
		std::cout << "===========================" << std::endl << std::endl;
		
		_parser = new Parsing(p_railPath, p_trainPath);
		_parser->checkInputError();
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m" << e.what() << "\e[0m" << "\n🤓☝️  Tips: --help to see how to create inputs files." << std::endl;
		return false;
	}
	return true;
}

bool Simulation::factoryObject() {
	try {
		std::cout << "===========================" << std::endl;
		std::cout << "      Factory process      " << std::endl;
		std::cout << "===========================" << std::endl << std::endl;

		_factory = new Factory();
		_factory->createNodes(_parser->getNodes());
		_nodesList = _factory->getNodes();
		_factory->createRails(_parser->getRails());
		_railsList = _factory->getRails();
		_factory->createTrains(_parser->getTrains());
		_trainsList = _factory->getTrains();
		_graph = new Graph(_nodesList, _railsList);
		_graph->createNetwork(_parser->getRails());
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m[ERROR] factory: " << e.what() << "\e[0m" << std::endl;
		return false;
	}
	return true;
}

bool Simulation::pathFinder() {
	try {
		std::cout << "===========================" << std::endl;
		std::cout << "    Pathfinder process    " << std::endl;
		std::cout << "===========================" << std::endl << std::endl;

		_pathfinder = new Pathfinder(_graph);
		for (std::vector<Train*>::iterator it = _trainsList.begin(); it != _trainsList.end(); ++it) {
			_paths[*it] = _pathfinder->findOptimalPath((*it)->getDepartureStation(), (*it)->getArrivalStation(), *it);
		}
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m[ERROR] pathfinder: " << e.what() << "\e[0m" << std::endl;
		return false;
	}
	return true;
}

bool Simulation::runSimulation(long int p_startTime) {
	try {
		std::cout << "===========================" << std::endl;
		std::cout << "     Simulation process    " << std::endl;
		std::cout << "===========================" << std::endl << std::endl;

		_trainManager = new TrainManager(_graph, _trainsList, _paths, p_startTime);
		_engine = new SimulationEngine(_trainManager, _graph, _paths, _deltaTime, p_startTime);
		_engine->run();
		
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m[ERROR] simulation: " << e.what() << "\e[0m" << std::endl;
		return false;
	}
	return true;
}
