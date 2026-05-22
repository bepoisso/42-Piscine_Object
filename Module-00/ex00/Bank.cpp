#include "Bank.hpp"

Bank::Bank(int newLiquidity) : liquidity(newLiquidity), currentId(0) {
	if (newLiquidity < 0)
		throw std::runtime_error("error: can't create Bank, negative value");
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
const int& Bank::getLiquidity() const {
	return liquidity;
}

const Account& Bank::getAccount(int id) const {
	for (std::vector<Account*>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
		if ((*it)->getId() == id) {
			return **it;
		}
	}
	throw std::runtime_error("error: no account found for this id");
}


/* Methode */
void Bank::createAccount(int initialValue) {
	Account* a = new Account(currentId++, initialValue);
	clientAccounts.push_back(a);
}

void Bank::deletAccount(int id) {
	for (std::vector<Account*>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
		if ((*it)->getId() == id) {
			delete *it;
			clientAccounts.erase(it);
			return;
		}
	}
	throw std::runtime_error("error: no account found for this id");
}

void Bank::editAccount(int id, int newValue) {
	if (newValue < 0)
		throw std::runtime_error("error: can't edit Account, negative value");

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
	if (addValue < 0)
		throw std::runtime_error("error: can't deposit on Account, negative value");
	
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
	if (addValue < 0)
		throw std::runtime_error("error: can't loan on Account, negative value");

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
	if (minudValue < 0)
		throw std::runtime_error("error: can't withdraw on Account, negative value");

	for (std::vector<Account*>::iterator it = clientAccounts.begin();
		it != clientAccounts.end();
		++it) {
			if ((*it)->getId() == id) {
				if ((*it)->getValue() >= minudValue)
					(*it)->setValue((*it)->getValue() - minudValue);
			}
		}
}

const Account& Bank::operator[](int id) const {
	return getAccount(id);
}


