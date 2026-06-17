#pragma once

#include "command.hpp"

class PakageReductionDiscount : public Command {
private:
	// Attributes

public:
	PakageReductionDiscount(std::string newClient, std::string newDate, std::map<std::string, int> newArticlesPrice);
	~PakageReductionDiscount();

/* Methode */
	int	get_total_price() const {
		int total = get_raw_total_price();

		if (total > 150)
			return total - 10;
		return total;
	}

};

PakageReductionDiscount::PakageReductionDiscount(std::string newClient, std::string newDate, std::map<std::string, int> newArticlesPrice)
	: Command(newClient, newDate, newArticlesPrice) {}

PakageReductionDiscount::~PakageReductionDiscount() {}
