#include "Account.hpp"

Account::Account(int newId, int newValue) : id(newId), value(newValue) {
	if (newValue < 0)
		throw std::runtime_error("error: can't create Account, negative value");
}

Account::~Account() {
}

/* Operator */

/* Getter / Setter */

const int& Account::getId() const {
	return id;
}
const int& Account::getValue() const {
	return value;
}

void Account::setValue(int newValue) {
	value = newValue;
}

/* Methode */
