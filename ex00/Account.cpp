#include "Account.hpp"

Account::Account(int newId, int newValue) : id(newId), value(newValue) {
}

Account::~Account() {
}

/* Operator */

/* Getter / Setter */
const int Account::getId() const {
	return (id);
}
int Account::getValue() const {
	return(value);
}

const int Account::setValue(int newValue) { 
	this->value = newValue;
}

/* Methode */
