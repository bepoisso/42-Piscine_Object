#include <iostream>
#include <string>
#include <cstring>

#include "Simulation.hpp"

#define DELTA_TIME 1 		// secondes
#define START_TIME 28800	// secondes 28800 seconde = 08h00


int main(int ac, char **av) {

	if (ac == 2 && std::strcmp(av[1], "--help") == 0) {
		std::cout << "Choose your documentation :" << std::endl;
		std::cout << "[1] How to create Rail network file?" << std::endl;
		std::cout << "[2] How to create Train composition file?" << std::endl;
		int choice = 0;
		std::cout << "Enter choice: ";
		if (!(std::cin >> choice)) {
			std::cerr << "\e[0;31m[ERROR] invalid input\n" << "\e[0m" << std::endl;
			return 0;
		}
		switch (choice) {
			case 1:
				std::cout << "Rail network file format:\n  - list of stations, rails, ..." << std::endl;
				// TODO: Provide le --help pour voir comment cree les inputs
				break;
			case 2:
				std::cout << "Train composition file format:\n  - wagons, locomotive, order, ..." << std::endl;
				// TODO: Provide le --help pour voir comment cree les inputs
				break;
			default:
				std::cout << "Unknown choice. Use 1 or 2." << std::endl;
				break;
		}		return 0;
	} else if (ac != 3) {
		std::cerr << "\e[0;31m[ERROR] wrong number of arguments\n" << "\e[0m" << "Use  ./exec ./path/to/rail_network ./path/to/train_compose\n🤓☝️  Tips: --help to see how to create them" << std::endl;
		return 1;
	}

	std::cout << "======================================" << std::endl;
	std::cout << "      MODULE 05 - TRAIN YOURSELF      " << std::endl;
	std::cout << "======================================" << std::endl << std::endl;

	Simulation simulation(DELTA_TIME);
	
	if (!simulation.parseFiles(av[1], av[2]))
		return 1;
	if (!simulation.factoryObject())
		return 1;
	if (!simulation.pathFinder())
		return 1;
	if (!simulation.runSimulation(START_TIME))
		return 1;
	return 0;
}
