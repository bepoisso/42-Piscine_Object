#include <iostream>
#include "Bank.hpp"
#include "Account.hpp"

int main(void) {
	try {
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
		bank.loan(1, 100000000);
		std::cout << bank << std::endl;
		bank.loan(1, 1000);
		std::cout << bank << std::endl;

		const Account& a = bank.getAccount(1);
		const Account& b = bank[1];

		if (&a != &b)
			std::cout << "[FAIL] bad getAccount" << std::endl;
		else
			std::cout << "[PASS] getAccount() id: " << a.getId() << ", bank[] id: " << a.getId() << ", is the same" << std::endl;

	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
