#include "Simulation.hpp"

Simulation::Simulation() : _parser(NULL) {
	
}

Simulation::~Simulation() {
	delete _parser;
}

void Simulation::parseFiles(char* p_railPath, char* p_trainPath) {
	try
	{
		_parser = new Parsing(p_railPath, p_trainPath, this);
		_parser->checkInputError();
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
}
