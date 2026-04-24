#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>


#include "School.hpp"

#define MAX_DAY 110

int main()
{
	std::srand(std::time(NULL));

	std::cout << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "             Module 04 - Ex05 : Facade" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "============================================" << std::endl;
	std::cout << "            Initialization" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "--- Creating Mandatory Rooms ---" << std::endl;
	School school;
	
	std::cout << "\n\n============================================" << std::endl;
	std::cout << "           Start school simulation" << std::endl;
	std::cout << "============================================" << std::endl << std::endl;

	for (int i = 0; i < MAX_DAY; ++i) {
		if (school.isAllWorkDone() == true)
			break;
		school.runDayRoutine();
	}

	std::cout << "\n============================================" << std::endl;
	std::cout << "           End of school simulation" << std::endl;
	std::cout << "============================================" << std::endl;

	return 0;
}
