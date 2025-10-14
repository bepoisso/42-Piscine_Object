#pragma once

#include <iostream>

class Account {
private:
	// Attributes
	const int id;
	int value;
	
	
	public:
	Account(int newId, int newValue);
	~Account();
	
	/* Operator */
	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
	{
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
		return (p_os);
	}
	
	/* Getter / Setter */
	const int getId() const;
	int getValue() const;

	const int setValue(int newValue);
/* Methode */

};
