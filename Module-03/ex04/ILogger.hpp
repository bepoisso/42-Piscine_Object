#pragma once

#include <string>

class ILogger {
private:
	// Attributes

public:
	ILogger(/* Data */) {}
	virtual ~ILogger() {}

/* Methode */
	virtual void write(std::string msg) = 0;
};
