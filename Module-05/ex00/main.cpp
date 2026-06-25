#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Config.hpp"
#include "Simulation.hpp"

int main(int ac, char **av) {

	std::srand(std::time(NULL));

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
			case 1: {
					std::ifstream f("./how_to_create_rail_network.txt");

					if (!f.is_open()) {
						std::cerr << "\e[0;31m[ERROR] cannot open ./how_to_create_rail_network.txt\n" << "\e[0m" << std::endl;
						break;
					}

					std::string line;

					while (std::getline(f, line))
						std::cout << line << std::endl;

					f.close();
				}
				break;
			case 2: {
				std::ifstream f("./how_to_create_trains.txt");

					if (!f.is_open()) {
						std::cerr << "\e[0;31m[ERROR] cannot open ./how_to_create_rail_network.txt\n" << "\e[0m" << std::endl;
						break;
					}

					std::string line;

					while (std::getline(f, line))
						std::cout << line << std::endl;

					f.close();
			}
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
	std::cout << "Done ✅" << std::endl << std::endl;
	if (!simulation.factoryObject())
		return 1;
	std::cout << "Done ✅" << std::endl << std::endl;
	if (!simulation.pathFinder())
		return 1;
	std::cout << "Done ✅" << std::endl << std::endl;
	if (!simulation.runSimulation(START_TIME))
		return 1;
	std::cout << "Done ✅" << std::endl << std::endl;
	return 0;
}
