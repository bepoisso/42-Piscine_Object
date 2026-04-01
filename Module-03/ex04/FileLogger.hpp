#pragma once

#include <fstream>
#include <string>

#include "ILogger.hpp"
#include "IHeaderProvider.hpp"

class FileLogger : public ILogger{
private:
	// Attributes
	std::ofstream _out;
	const IHeaderProvider* _header;


public:
	FileLogger(const std::string& path, const IHeaderProvider* header = 0) : _out(path.c_str()), _header(header) {
		if (!_out.is_open())
			throw std::runtime_error("Fail to open file :" + path);
	}

	virtual ~FileLogger() {}

	/* Methode */
	virtual void write(std::string msg) {
		if (_header)
			_out << _header->getHeader();
		_out << msg << std::endl;
		_out.flush();
	}

};
