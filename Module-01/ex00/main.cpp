#include <iostream>
#include <string>
#include <vector>

#include "Shovel.hpp"
#include "Worker.hpp"

int main () {
	std::cout << std::endl << "--- CREATE ---" << std::endl;
	Worker bob("Bob");
	Worker alex("Alex");
	Shovel shov;

	std::cout << std::endl << "--- BOB USE ---" << std::endl;
	bob.giveShovel(&shov);
	bob.takeShovel();
	bob.removeShovel();
	bob.takeShovel();
	bob.giveShovel(&shov);

	std::cout << std::endl << "--- ALEX & BOB USE ---" << std::endl;
	alex.giveShovel(&shov);
	alex.takeShovel();
	bob.takeShovel();

	std::cout << std::endl << "--- ALEX USE ---" << std::endl;
	alex.takeShovel();
	alex.takeShovel();
	alex.takeShovel();
	alex.takeShovel();

	std::cout << std::endl << "--- BOB STEAL SHOVEL ---" << std::endl;
	bob.giveShovel(&shov);
	alex.takeShovel();
	alex.takeShovel();
	bob.takeShovel();
	
	std::cout << std::endl << "--- DESTRUCTOR ---" << std::endl;

	return 0;
}
