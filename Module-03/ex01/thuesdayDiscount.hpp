#pragma once

#include "command.hpp"

class ThuesdayDiscount : public Command {
private:
	// Attributes

public:
	// Canonical Form
	ThuesdayDiscount(std::string newClient, std::string newDate, std::map<std::string, int> newArticlesPrice)
		: Command(newClient, newDate, newArticlesPrice) {}
	~ThuesdayDiscount() {}

/* Methode */

	int get_total_price() const {
		int total = get_raw_total_price();
		time_t date = getDate();
		std::tm *localDate = std::localtime(&date);

		if (localDate && localDate->tm_wday == 2)
			return total - ((total * 10) / 100);
		return total;
	}

};
