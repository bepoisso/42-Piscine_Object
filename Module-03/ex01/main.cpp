#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <cstdio>
#include <ctime>

#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

static bool	is_valid_date(const std::string &dateInput)
{
	int year = 0;
	int month = 0;
	int day = 0;

	if (std::sscanf(dateInput.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return false;
	std::tm t = {};
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_isdst = -1;
	return std::mktime(&t) != static_cast<time_t>(-1);
}

static bool	is_tuesday(const std::string &dateInput)
{
	int year = 0;
	int month = 0;
	int day = 0;

	if (std::sscanf(dateInput.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return false;
	std::tm t = {};
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_isdst = -1;
	if (std::mktime(&t) == static_cast<time_t>(-1))
		return false;
	return t.tm_wday == 2;
}

int main(void)
{
	int							choice;
	int							quantity;
	std::string					name;
	std::string 				date;
	std::map<std::string, int>	articlesPrice;
	std::map<std::string, int>	cart;

	articlesPrice["Banana"] = 2;
	articlesPrice["Orange"] = 3;
	articlesPrice["Apple"] = 1;
	articlesPrice["Abricot"] = 4;
	articlesPrice["Coconut"] = 5;

	std::cout << "=== MARKET PLACE ===" << std::endl << std::endl;
	std::cout << "name: ";
	std::getline(std::cin, name);
	for (char c : name) {
		if (std::isdigit(c)) {
			std::cerr << "Error: name cannot contain digits" << std::endl;
			return 1;
		}
	}

	std::cout << std::endl;
	std::cout << "date (YYYY-MM-DD) - ex thuesday: 2026-03-24: ";
	std::getline(std::cin, date);
	if (!is_valid_date(date)) {
		std::cerr << "Error: date must be in YYYY-MM-DD format" << std::endl;
		return 1;
	}
	
	std::cout << std::endl;
	
	ThuesdayDiscount thuesdayCmd(name, date, articlesPrice);
	PakageReductionDiscount packageCmd(name, date, articlesPrice);

	while (true) {
		std::cout << "CHOCE YOUR ITEMS:" << std::endl;
		std::cout << "1. Banana 2$\n2. Orange 3$\n3. Apple 1$\n4. Abricot 4$\n5. Coconut 5$\n0. Go to cart" << std::endl;
		std::cin >> choice;
		std::string items[] = {"Banana", "Orange", "Apple", "Abricot", "Coconut"};

		if (choice == 0)
			break;
		else if (choice > 5 || choice < 0)
			std::cout << "Invalide input" << std::endl;
		else {
			std::cout << "Quantity of " << items[choice - 1] << ": ";
			std::cin >> quantity;
			if (quantity > 0) {
				thuesdayCmd.addToCart(items[choice - 1], quantity);
				packageCmd.addToCart(items[choice - 1], quantity);
				cart[items[choice - 1]] += quantity;
			}
		}
	}
	std::cout << std::endl;
	thuesdayCmd.displayCart();

	int rawTotal = 0;
	for (std::map<std::string, int>::iterator it = cart.begin(); it != cart.end(); ++it)
		rawTotal += articlesPrice[it->first] * it->second;

	bool applyThuesday = is_tuesday(date);
	bool applyPackage = (rawTotal > 150);
	int totalAfterBoth = rawTotal;

	if (applyThuesday)
		totalAfterBoth = totalAfterBoth - ((totalAfterBoth * 10) / 100);
	if (applyPackage)
		totalAfterBoth = totalAfterBoth - 10;

	std::cout << std::endl;
	std::cout << "Total price : " << rawTotal << "$" << std::endl;
	if (applyThuesday)
		std::cout << "(Thuesday Discount 10%)" << std::endl;
	if (applyPackage)
		std::cout << "(Pakage Reduction Discount 10$)" << std::endl;
	if (applyThuesday || applyPackage)
		std::cout << "Total price with discount : " << totalAfterBoth << "$" << std::endl;
	else
		std::cout << "Total price without discount : " << rawTotal << "$" << std::endl;
	return 0;
}
