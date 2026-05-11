/**
 * @file Parsing.hpp
 * @brief Parsing class - Read and validate input files
 * 
 * @details
 * Parses rail network and train composition files, validates their format,
 * and exposes the raw data to the simulation.
 * 
 * @note
 * principles SRP, Defensive validation
 */

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Utils.hpp"

#include "Simulation.hpp"


class Parsing {
private:
	const std::string _railNetworkPath;
	const std::string _trainComposePath;

	std::ifstream* _railnetworkFile;
	std::ifstream* _trainComposeFile;

	std::vector<std::string> _nodes;
	std::vector<std::string> _rails;
	std::vector<std::string> _trains;

	void railNetworkChecker();
	void railChecker(std::string p_line);
	void nodeChecker(std::string p_line);
	void checkDoubleRail(std::string trajectID);
	bool isEmptyNode(std::string p_node);

	void trainComposeChecker();
	void trainChecker(std::string p_line);
	void checkDoubleTrain(std::string p_name);

	bool isemptyFile(std::ifstream* p_file);
	bool isFloat(std::string p_arg);
	bool isInt(std::string p_arg);
	bool isHours(std::string p_arg);
	bool isANode(std::string p_name);
public:
	Parsing(const std::string p_railNetworkpath, const std::string p_trainComposePath);
	~Parsing();

	void checkInputError();
	std::vector<std::string> 	getNodes() const { return _nodes; }
	std::vector<std::string> 	getRails() const { return _rails; }
	std::vector<std::string> 	getTrains() const { return _trains; }
};
