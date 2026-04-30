#include "Utils.hpp"

std::vector<std::string> split(std::string p_line, const std::string& delimiter) {
	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;
	while ((pos = p_line.find(delimiter)) != std::string::npos) {
		token = p_line.substr(0, pos);
		tokens.push_back(token);
		p_line.erase(0, pos + delimiter.length());
	}
	tokens.push_back(p_line);

	return tokens;
}
