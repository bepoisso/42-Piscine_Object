#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "Simulation.hpp"


class Parsing
{
private:
	std::string _railNetworkPath;
	std::string _trainComposePath;
	Simulation* _simulationMediator;

	std::ifstream* _railnetworkFile;
	std::ifstream* _trainComposeFile;

	void _railChecker();
	void _trainChecker();
	bool _isemptyFile(std::ifstream* p_file);
public:
	Parsing(std::string p_railNetworkpath, std::string p_trainComposePath, Simulation* p_simulationMediator);
	~Parsing();

	void checkInputError();
};

