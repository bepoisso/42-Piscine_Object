#pragma once

#include "command.hpp"

class ThuesdayDiscount : public Command {
private:
	// Attributes

public:
	// Canonical Form
	ThuesdayDiscount(int newId, std::string newClient, std::string newDate, std::map<std::string, int> newArticlesPrice)
		: Command(newId, newClient, newDate, newArticlesPrice) {}
	~ThuesdayDiscount() {}
	ThuesdayDiscount(const ThuesdayDiscount &other) : Command(other) {}
	ThuesdayDiscount &operator=(const ThuesdayDiscount &other) {
		if (this != &other)
			Command::operator=(other);
		return *this;
	}

/* Methode */

	virtual int get_total_price() const {
		int total = get_raw_total_price();
		time_t date = getDate();
		std::tm *localDate = std::localtime(&date);

		if (localDate && localDate->tm_wday == 2)
			return total - ((total * 10) / 100);
		return total;
	}

};
