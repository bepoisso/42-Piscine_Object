#pragma once

#include "command.hpp"

class PakageReductionDiscount : public Command {
private:
	// Attributes

public:
	// Canonical Form
	PakageReductionDiscount(int newId, std::string newClient, std::string newDate, std::map<std::string, int> newArticlesPrice);
	~PakageReductionDiscount();
	PakageReductionDiscount(const PakageReductionDiscount &other);
	PakageReductionDiscount &operator=(const PakageReductionDiscount &other);

/* Methode */
	virtual int	get_total_price() const {
		int total = get_raw_total_price();

		if (total > 150)
			return total - 10;
		return total;
	}

};

PakageReductionDiscount::PakageReductionDiscount(int newId, std::string newClient, std::string newDate, std::map<std::string, int> newArticlesPrice)
	: Command(newId, newClient, newDate, newArticlesPrice) {}

PakageReductionDiscount::~PakageReductionDiscount() {}

PakageReductionDiscount::PakageReductionDiscount(const PakageReductionDiscount &other)
	: Command(other) {}

PakageReductionDiscount &PakageReductionDiscount::operator=(const PakageReductionDiscount &other) {
	if (this != &other)
		Command::operator=(other);
	return *this;
}

