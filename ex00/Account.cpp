#include "Account.hpp"

Account::Account(int newId, int newValue) : id(newId), value(newValue) {
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
