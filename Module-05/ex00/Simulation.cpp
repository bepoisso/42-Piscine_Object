#include "Simulation.hpp"

Simulation::Simulation() : _parser(nullptr), _factory(nullptr) {
	
}

Simulation::~Simulation() {
	delete _parser;
	delete _factory;
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
		_parser->D_printList(_parser->getNodes());
		_parser->D_printList(_parser->getRails());
		_parser->D_printList(_parser->getTrains());
		return true;
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m" << e.what() << "\e[0m" << "\n🤓☝️  Tips: --help to see how to create inputs files." << std::endl;
		return false;
	}
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
		_factory->D_printNodesConnections();
		return true;
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m[ERROR] factory: " << e.what() << "\e[0m" << std::endl;
		return false;
	}
}
