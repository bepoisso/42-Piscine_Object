#include <iostream>
#include <string>
#include <cstring>

#include "Colors.hpp"
#include "Simulation.hpp"


int main(int ac, char **av) {


	if (ac == 2 && std::strcmp(av[1], "--help") == 0) {
		std::cout << BLUE;
		// TODO: Provide le --help pour voir comment cree les inputs
		std::cout << RESET;
		return 0;
	} else if (ac != 3) {
		std::cerr << RED << "[ERROR] wrong number of arguments\n" << BLUE << "Use ./exec ./path/to/rail_network ./path/to/train_compose\nType --help to see how to create them" << RESET << std::endl;
		return 1;
	}

	// Simulation simulation();
	// simulation.paths(av[1], av[2]);

	return 0;
}
