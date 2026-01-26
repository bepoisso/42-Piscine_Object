#include "Bank.hpp"

Bank::Bank(int newLiquidity) : liquidity(newLiquidity), currentId(0) {
}

Bank::~Bank() {
	for (std::vector<Account*>::iterator it = clientAccounts.begin();
		 it != clientAccounts.end();
		 ++it) {
		delete *it;
	}
}


/* Operator */

/* Getter / Setter */
int Bank::getLiquidity() const {
	return liquidity;
}

void Bank::setLiquidity(int newLiquidity) {
	liquidity = newLiquidity;
}


/* Methode */
	void Bank::createAccount(int initialValue) {
		Account* a = new Account(currentId++, initialValue);
		clientAccounts.push_back(a);
	}

	void Bank::deletAccount(int id) {

	}

	void Bank::editAccount(int id, int newValue) {

	}
