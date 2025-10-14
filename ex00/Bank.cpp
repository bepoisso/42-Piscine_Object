#include "Bank.hpp"

Bank::Bank(int newLiquidity) : liquidity(newLiquidity), currentId(0) {
}

Bank::~Bank() {
}


/* Operator */

/* Getter / Setter */
const int Bank::getLiquidity() const {
	return liquidity;
}

const int Bank::setLiquidity(int newLiquidity) {
	liquidity = newLiquidity;
}


/* Methode */
	void Bank::createAccount(int initialValue) {
		Account a(currentId++, initialValue);
		clientAccounts.push_back(&a);
	}

	void Bank::deletAccount(int id) {

	}

	void Bank::editAccount(int id, int newValue) {

	}
