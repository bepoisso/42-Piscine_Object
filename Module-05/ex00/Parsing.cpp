#include "Parsing.hpp"
#include <stdexcept>


Parsing::Parsing(std::string p_railNetworkpath, std::string p_trainComposePath, Simulation* p_simulationMediator) : _railNetworkPath(p_railNetworkpath), _trainComposePath(p_trainComposePath), _simulationMediator(p_simulationMediator), _railnetworkFile(NULL), _trainComposeFile(NULL) {
	(void)_simulationMediator;
}

Parsing::~Parsing() {
	delete _railnetworkFile;
	delete _trainComposeFile;
}

void Parsing::checkInputError() {
	_railnetworkFile = new std::ifstream(_railNetworkPath);
	_trainComposeFile = new std::ifstream(_trainComposePath);

	if (!_railnetworkFile->is_open()) {
		throw std::runtime_error("[ERROR] Cannot open file " + _railNetworkPath);
	}
	if (!_trainComposeFile->is_open()) {
		throw std::runtime_error("[ERROR] Cannot open file " + _trainComposePath);
	}
	_railChecker();
	_trainChecker();

}

void Parsing::_railChecker() {
	std::string line;
	if (_isemptyFile(_railnetworkFile))
		throw std::runtime_error("[ERROR] parsing: empty file: " + _railNetworkPath);
	while (std::getline(*_railnetworkFile, line)) { 
	if (line.find("Rail ") != 0 && line.find("Node ") != 0)
			throw std::runtime_error("[ERROR] parsing: bad identification name in file: " + _railNetworkPath);
	}
}

void Parsing::_trainChecker() {

}

bool Parsing::_isemptyFile(std::ifstream* p_file) {
	std::string line;
	std::getline(p_file, line);
	if (line.empty())
		return true;
	return false;
}

