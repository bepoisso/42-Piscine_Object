#pragma once

#include <string>
#include <ctime>

#include "IHeaderProvider.hpp"

class ConstHeader : public IHeaderProvider {
private:
	// Attributes
	const std::string _header;

public:
	ConstHeader(std::string header) : _header(header) {}
	~ConstHeader() {}


/* Methode */
	const std::string getHeader() const { return _header; }


};

class DateHeader : public IHeaderProvider{
private:
	// Attributes

public:
	DateHeader() {}
	~DateHeader() {}


/* Methode */
	const std::string getHeader() const {
		std::time_t now = std::time(NULL);
		std::tm* timeinfo = std::localtime(&now);
		char buffer[32];
		if (timeinfo == NULL || std::strftime(buffer, sizeof(buffer), "[%d/%m/%Y - %H:%M:%S] ", timeinfo) == 0)
			return "[invalid-date] ";
		return std::string(buffer);
	}

};
