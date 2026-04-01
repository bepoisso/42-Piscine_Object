#include <iostream>
#include <vector>
#include <string>

#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "OstreamLogger.hpp"
#include "IHeaderProvider.hpp"
#include "Header.hpp"

int main() {
	std::vector<ILogger*> loggers;
	std::vector<std::string> messages;

	messages.push_back("Application started");
	messages.push_back("Processing data...");
	messages.push_back("Operation completed");
	messages.push_back("Shutting down");

	ConstHeader constHeader("[LOG] ");
	DateHeader dateHeader;

	try {
		FileLogger* fileLogger1 = new FileLogger("log_no_header.txt", 0);
		loggers.push_back(fileLogger1);

		FileLogger* fileLogger2 = new FileLogger("log_const_header.txt", &constHeader);
		loggers.push_back(fileLogger2);

		FileLogger* fileLogger3 = new FileLogger("log_date_header.txt", &dateHeader);
		loggers.push_back(fileLogger3);

		OstreamLogger* coutLogger1 = new OstreamLogger(std::cout, 0);
		loggers.push_back(coutLogger1);

		OstreamLogger* coutLogger2 = new OstreamLogger(std::cout, &constHeader);
		loggers.push_back(coutLogger2);

		OstreamLogger* cerrLogger = new OstreamLogger(std::cerr, &dateHeader);
		loggers.push_back(cerrLogger);

		std::cout << "=== LOGGING MESSAGES ===" << std::endl;
		for (size_t i = 0; i < messages.size(); ++i) {
			std::cout << "\n--- Message " << (i + 1) << " ---" << std::endl;
			for (size_t j = 0; j < loggers.size(); ++j) {
				loggers[j]->write(messages[i]);
			}
		}

		for (size_t i = 0; i < loggers.size(); ++i) {
			delete loggers[i];
		}
		loggers.clear();

		std::cout << "\n=== ALL LOGS COMPLETED ===" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
