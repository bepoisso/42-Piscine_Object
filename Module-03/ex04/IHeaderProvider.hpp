#pragma once

#include <string>

class IHeaderProvider {
private:
	// Attributes

public:
	IHeaderProvider(/* Data */) {}
	virtual ~IHeaderProvider() {}


/* Methode */
	virtual const std::string getHeader() const = 0;

};
