#pragma once

#include <iostream>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>


class Command {
private:
	// Attributes
	int 				id;
	time_t				date;
	std::string			client;
	std::map<std::string, int>	articles;
	std::map<std::string, int>	articlesPrice;

	bool			parseDate(const std::string &dateInput, time_t &outDate) const;

protected:
	time_t			getDate() const;
	int				get_raw_total_price() const;

public:
	// Canonical Form
	Command(int newId, std::string newClient, std::string dateInput, std::map<std::string, int> newArticlesPrice);
	virtual ~Command();
	Command(const Command &other);
	Command &operator=(const Command &other);

/* Methode */
	void			addToCart(std::string name, int value);
	void			displayCart() const;
	virtual int		get_total_price() const;
};



Command::Command(int newId, std::string newClient, std::string dateInput, std::map<std::string, int> newArticlesPrice)
	: id(newId), date(time(NULL)), client(newClient), articlesPrice(newArticlesPrice) {
	parseDate(dateInput, date);
}

Command::~Command() {}

Command::Command(const Command &other) {
	*this = other;
}

Command &Command::operator=(const Command &other) {
	if (this != &other) {
		id = other.id;
		date = other.date;
		client = other.client;
		articles = other.articles;
		articlesPrice = other.articlesPrice;
	}
	return *this;
}

bool Command::parseDate(const std::string &dateInput, time_t &outDate) const {
	int year = 0;
	int month = 0;
	int day = 0;

	int parsed = std::sscanf(dateInput.c_str(), "%d-%d-%d", &year, &month, &day);
	if (parsed != 3)
		return false;

	std::tm timeInfo = {};
	timeInfo.tm_year = year - 1900;
	timeInfo.tm_mon = month - 1;
	timeInfo.tm_mday = day;
	timeInfo.tm_isdst = -1;

	time_t result = std::mktime(&timeInfo);
	if (result == static_cast<time_t>(-1))
		return false;
	outDate = result;
	return true;
}

/* Methode */
void Command::addToCart(std::string name, int value) {
	articles[name] = value;
}

void Command::displayCart() const {
	char buffer[64];
	std::tm *localDate = std::localtime(&date);
	if (localDate)
		std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", localDate);
	else
		std::snprintf(buffer, sizeof(buffer), "invalid date");

	std::cout << "=== CART ===" << std::endl;
	std::cout << "Command for " << client << " date: " << buffer << std::endl << std::endl;
	for (auto &item : articles) {
		std::cout << item.first << ": " << item.second << std::endl;
	}
}

time_t Command::getDate() const {
	return date;
}

int	Command::get_raw_total_price() const {
	int total = 0;
	for (std::map<std::string, int>::const_iterator item = articles.begin(); item != articles.end(); ++item) {
		std::map<std::string, int>::const_iterator itPrice = articlesPrice.find(item->first);
		if (itPrice != articlesPrice.end())
			total += itPrice->second * item->second;
	}
	return total;
}

int	Command::get_total_price() const {
	return get_raw_total_price();
}
