#pragma once

#include <iostream>
#include <string>

#include "ILogger.hpp"
#include "IHeaderProvider.hpp"

class OstreamLogger : public ILogger {
private:
	// Attributes
	std::ostream& _out;
	const IHeaderProvider* _header;

public:
	OstreamLogger(std::ostream& out, const IHeaderProvider* header = 0) : _out(out), _header(header) {}

	virtual ~OstreamLogger() {}

	/* Methode */
	virtual void write(std::string msg) {
		if (_header)
			_out << _header->getHeader();
		_out << msg << std::endl;
		_out.flush();
	}
};
