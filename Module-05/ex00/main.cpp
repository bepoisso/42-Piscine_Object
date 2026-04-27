#include <iostream>
#include <string>
#include <cstring>

#include "Simulation.hpp"


int main(int ac, char **av) {


	if (ac == 2 && std::strcmp(av[1], "--help") == 0) {
		// TODO: Provide le --help pour voir comment cree les inputs
		return 0;
	} else if (ac != 3) {
		std::cerr << "[ERROR] wrong number of arguments\n" << "Use ./exec ./path/to/rail_network ./path/to/train_compose\nType --help to see how to create them" << std::endl;
		return 1;
	}

	Simulation simulation;
	
	simulation.parseFiles(av[1], av[2]);

	return 0;
}
