#include <iostream>
#include "Bank.hpp"
#include "Account.hpp"

int main(void) {
	Bank bank(10000);
	bank.createAccount(0);
	bank.createAccount(0);

	std::cout << bank << std::endl;
	bank.deposit(0, 100);
	std::cout << bank << std::endl;
	bank.deposit(1, 10000);
	std::cout << bank << std::endl;

	bank.withdraw(1, 100);
	std::cout << bank << std::endl;
	bank.deposit(1, 100);
	std::cout << bank << std::endl;

	bank.withdraw(0, 200);
	std::cout << bank << std::endl;
	bank.loan(1, 1000000);
	std::cout << bank << std::endl;
	bank.loan(1, 10);
	std::cout << bank << std::endl;

	return (0);
}
