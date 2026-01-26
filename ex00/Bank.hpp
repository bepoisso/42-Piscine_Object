#pragma once

#include <iostream>
#include <vector>
#include "Account.hpp"

class Account;

class Bank {
private:
	// Attributes
	int liquidity;
	std::vector<Account *> clientAccounts;
	int currentId;

public:
	Bank(int newLiquidity);
	~Bank();

/* Operator */
friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (std::vector<Account*>::const_iterator it = p_bank.clientAccounts.begin();
	 		it != p_bank.clientAccounts.end();
	 		++it) {
				p_os << **it << std::endl;
		}
		return (p_os);
	}

/* Getter / Setter */
	int getLiquidity() const;
	void setLiquidity(int newLiquidity);


/* Methode */
	void createAccount(int initialValue);
	void deletAccount(int id);
	void editAccount(int id, int newValue);

	

};
