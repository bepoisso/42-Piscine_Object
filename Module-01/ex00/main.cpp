#include <iostream>
#include <string>
#include <vector>

#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Worker.hpp"

int main () {
	std::cout << std::endl << "--- CREATE ---" << std::endl;
	Worker bob("Bob");
	Worker alex("Alex");
	Shovel shov;
	Hammer ham;

	std::cout << std::endl << "--- BOB TAKE TOOLS ---" << std::endl;
	bob.giveTool(&shov);
	bob.giveTool(&ham);
	bob.takeTools();

	std::cout << std::endl << "--- ALEX TAKE SHOVEL ---" << std::endl;
	alex.giveTool(&shov);
	alex.takeTool(&shov);
	bob.takeTool(&shov);

	std::cout << std::endl << "--- BOB RETURN ALL TOOLS ---" << std::endl;
	bob.removeTools();
	bob.takeTools();
	alex.takeTools();

	std::cout << std::endl << "--- ALEX RETURN SHOVEL ---" << std::endl;
	alex.removeTool(&shov);
	alex.takeTools();
	
	std::cout << std::endl << "--- DESTRUCTOR ---" << std::endl;

	return 0;
}
