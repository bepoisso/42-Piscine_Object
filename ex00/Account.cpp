#include "Account.hpp"

Account::Account(int newId, int newValue) : id(newId), value(newValue) {
}

Account::~Account() {
}

/* Operator */

/* Getter / Setter */
int Account::getId() const {
	return (id);
}
int Account::getValue() const {
	return(value);
}

/* Methode */
