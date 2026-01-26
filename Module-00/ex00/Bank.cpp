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
		for (std::vector<Account*>::iterator it = clientAccounts.begin();
			 it != clientAccounts.end();
			 ++it) {
			if ((*it)->getId() == id) {
				delete *it;
				clientAccounts.erase(it);
				return;
			}
		}
	}

	void Bank::editAccount(int id, int newValue) {
		for (std::vector<Account*>::iterator it = clientAccounts.begin();
			 it != clientAccounts.end();
			 ++it) {
			if ((*it)->getId() == id) {
				(*it)->setValue(newValue);
				return;
			}
		}
	}

	void Bank::deposit(int id, int addValue) {
		for (std::vector<Account*>::iterator it = clientAccounts.begin();
			it != clientAccounts.end();
			++it) {
				if ((*it)->getId() == id) {
					int fee = (addValue*5)/100;
					int valueNoFee = addValue - fee;
					this->liquidity += fee;
					(*it)->setValue((*it)->getValue() + valueNoFee);
				}
			}
	}

	void Bank::loan(int id, int addValue) {
		for (std::vector<Account*>::iterator it = clientAccounts.begin();
			it != clientAccounts.end();
			++it) {
				if ((*it)->getId() == id) {
					if (this->liquidity >= addValue) {
						this->liquidity -= addValue;
						(*it)->setValue((*it)->getValue() + addValue);
					}
					return;
				}
			}
	}

	void Bank::withdraw(int id, int minudValue) {
		for (std::vector<Account*>::iterator it = clientAccounts.begin();
			it != clientAccounts.end();
			++it) {
				if ((*it)->getId() == id) {
					if ((*it)->getValue() >= minudValue)
						(*it)->setValue((*it)->getValue() - minudValue);
				}
			}
	}
