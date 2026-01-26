#include <iostream>
#include "Bank.hpp"
#include "Account.hpp"

int main(void) {
	Bank bank(10000);
	bank.createAccount(0);
	bank.createAccount(0);

	std::cout << bank << std::endl;

	return (0);
}
