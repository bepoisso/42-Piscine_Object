#include "Simulation.hpp"

Simulation::Simulation() : _parser(NULL) {
	
}

Simulation::~Simulation() {
	delete _parser;
}

void Simulation::parseFiles(char* p_railPath, char* p_trainPath) {
	try
	{
		_parser = new Parsing(p_railPath, p_trainPath);
		_parser->checkInputError();
		_parser->D_printList(_parser->getNodes());
		_parser->D_printList(_parser->getRails());
		_parser->D_printList(_parser->getTrains());
	} catch(const std::exception& e) {
		std::cerr << "\e[0;31m" << e.what() << "\e[0m" << "\n🤓☝️  Tips: --help to see how to create inputs files." << std::endl;
		return;
	}
}
