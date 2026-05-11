#include "Parsing.hpp"
#include <stdexcept>
#include <cctype>
#include <sys/stat.h>


Parsing::Parsing(std::string p_railNetworkpath, std::string p_trainComposePath) : _railNetworkPath(p_railNetworkpath), _trainComposePath(p_trainComposePath), _railnetworkFile(NULL), _trainComposeFile(NULL) {
}

Parsing::~Parsing() {
	if (_railnetworkFile) {
		if (_railnetworkFile->is_open())
			_railnetworkFile->close();
		delete _railnetworkFile;
		_railnetworkFile = NULL;
	}

	if (_trainComposeFile) {
		if (_trainComposeFile->is_open())
			_trainComposeFile->close();
		delete _trainComposeFile;
		_trainComposeFile = NULL;
	}
}

void Parsing::checkInputError() {
	struct stat buffer;
	if (stat(_railNetworkPath.c_str(), &buffer) == 0 && S_ISDIR(buffer.st_mode))
		throw std::runtime_error("[ERROR] parsing: " + _railNetworkPath + " is a directory, not a file");

	if (stat(_trainComposePath.c_str(), &buffer) == 0 && S_ISDIR(buffer.st_mode))
		throw std::runtime_error("[ERROR] parsing: " + _trainComposePath + " is a directory, not a file");

	_railnetworkFile = new std::ifstream(_railNetworkPath);
	_trainComposeFile = new std::ifstream(_trainComposePath);

	if (!_railnetworkFile->is_open()) {
		throw std::runtime_error("[ERROR] parsing: Cannot open file " + _railNetworkPath);
	}

	if (!_trainComposeFile->is_open()) {
		throw std::runtime_error("[ERROR] parsing: Cannot open file " + _trainComposePath);
	}

	railNetworkChecker();
	trainComposeChecker();
}

void Parsing::nodeChecker(std::string p_line) {
	p_line = p_line.substr(5);

	if (!p_line[0] || (p_line.find("City") != 0 && p_line.find("RailNode") != 0))
			throw std::runtime_error("[ERROR] parsing: bad node format; in file: " + _railNetworkPath + "\nline: Node " + p_line);

	for (size_t i = 0; p_line[i]; ++i) {
		if (!std::isalpha(p_line[i]))
			throw std::runtime_error("[ERROR] parsing: bad node format; in file: " + _railNetworkPath + "\nline: Node " + p_line);
	}

	for (std::vector<std::string>::iterator it = _nodes.begin(); it != _nodes.end(); ++it)
		if (p_line == *it)
			throw std::runtime_error("[ERROR] parsing: double node \"" + p_line + "\" detected; in file: " + _railNetworkPath + "\nline: Node " + p_line);

	_nodes.push_back(p_line);
}

void Parsing::checkDoubleRail(std::string trajectID) {
	std::vector<std::string> token;
	std::string currentName;
	std::string reverseCurrentName;

	for (std::vector<std::string>::iterator it = _rails.begin(); it != _rails.end(); ++it) {
		token = f_split((*it), " ");
		currentName = token[0] + " " + token[1];
		reverseCurrentName = token[1] + " " + token[0];

		if (trajectID == currentName)
			throw std::runtime_error("[ERROR] parsing: rail: \"" + currentName + "\" already exist; in file :" + _railNetworkPath);

		if (trajectID == reverseCurrentName)
			throw std::runtime_error("[ERROR] parsing: rail: \"" + reverseCurrentName + "\" already exist; in file :" + _railNetworkPath);
	}
}

bool Parsing::isEmptyNode(std::string p_node) {
	for (std::vector<std::string>::iterator it = _rails.begin(); it != _rails.end(); ++it) {
		std::vector<std::string> token = f_split(*it, " ");
		
		if (p_node == token[0] || p_node == token[1])
			return false;
	}
	
	return true;
}

void Parsing::railChecker(std::string p_line) {
	p_line = p_line.substr(5);
	std::vector<std::string> token = f_split(p_line, " ");

	if (token.size() != 4)
		throw std::runtime_error("[ERROR] parsing: bad number of arguments; in file: " + _railNetworkPath);

	bool firstNodeFound = false;
	bool secondNodeFound = false;
	bool doubleFound = false;

	for (std::vector<std::string>::iterator it = _nodes.begin(); it != _nodes.end(); ++it) {
		if (token[0] == *it && token[1] == *it)
			doubleFound = true;
		else if (token[0] == *it)
			firstNodeFound = true;
		else if (token[1] == *it)
			secondNodeFound = true;
	}

	if (doubleFound)
		throw std::runtime_error("[ERROR] parsing: double: " + token[0] + " cannot have the same departure and arrival node; in file :" + _railNetworkPath);
	else if (!firstNodeFound)
		throw std::runtime_error("[ERROR] parsing: " + token[0] + " is not a node; in file :" + _railNetworkPath);
	else if (!secondNodeFound)
		throw std::runtime_error("[ERROR] parsing: " + token[1] + " is not a node; in file :" + _railNetworkPath);

	if (!isFloat(token[2]) || std::stod(token[2]) < 1.0 || std::stod(token[2]) > 1000.0 )
		throw std::runtime_error("[ERROR] parsing: lenght:" + token[2] + " is not a valid arguments; in file :" + _railNetworkPath);

	if (!isFloat(token[3]) || std::stod(token[3]) < 50.0 || std::stod(token[3]) > 400.0)
		throw std::runtime_error("[ERROR] parsing: speed limit:" + token[3] + " is not a valid arguments; in file :" + _railNetworkPath);
	
	checkDoubleRail(token[0] + " " + token[1]);
	_rails.push_back(p_line);
}

void Parsing::railNetworkChecker() {
	std::string line;

	if (isemptyFile(_railnetworkFile))
		throw std::runtime_error("[ERROR] parsing: empty file: " + _railNetworkPath);

	while (std::getline(*_railnetworkFile, line)) {
		if (line.find("Rail ") != 0 && line.find("Node ") != 0)
			throw std::runtime_error("[ERROR] parsing: bad identification name; in file: " + _railNetworkPath);
		else if (line.find("Node ") == 0)
			nodeChecker(line);
		else if (line.find("Rail ") == 0)
			railChecker(line);
	}

	for (std::vector<std::string>::iterator it = _nodes.begin(); it != _nodes.end(); ++it) {
		if (isEmptyNode(*it))
			throw std::runtime_error("[ERROR] parsing: " + *it + " is not link to rails network; in file :" + _railNetworkPath);
	}
}

void Parsing::checkDoubleTrain(std::string p_name) {
	std::vector<std::string> token;

	for (std::vector<std::string>::iterator it = _trains.begin(); it != _trains.end(); ++it) {
		token = f_split((*it), " ");

		if (p_name == token[0])
			throw std::runtime_error("[ERROR] parsing: double " + p_name +  " detected; in file: " + _trainComposePath);
	}
}

void Parsing::trainChecker(std::string p_line) {
	std::vector<std::string> token = f_split(p_line, " ");

	if (token.size() != 9)
		throw std::runtime_error("[ERROR] parsing: bad number of arguments; in file: " + _trainComposePath + "\nExpected: train_name weight coefficient_of_friction maximum_acceleration_force maximum_brake_force departure_station arrival_station departure_time stop_duration\nExemple: TrainAB 80 0.05 356.0 30.0 CityA CityB 14h10 00h10");
	
	for (size_t i = 0; i != token[0].size(); ++i)
		if (!std::isalpha(token[0][i]))
			throw std::runtime_error("[ERROR] parsing: bad identification name: " + token[0] + "; in file: " + _trainComposePath);
	
	checkDoubleTrain(token[0]);

	if (!isInt(token[1]) || std::stoi(token[1]) < 1.0 || std::stoi(token[1]) > 1000.0)
		throw std::runtime_error("[ERROR] parsing: weight: " + token[1] + " is not a valid arguments; in file: " + _trainComposePath);

	if (!isFloat(token[2]) || std::stod(token[2]) <= 0.0 || std::stod(token[2]) > 1.0)
		throw std::runtime_error("[ERROR] parsing: friction: " + token[2] + " is not a valid arguments; in file: " + _trainComposePath);

	if (!isFloat(token[3]) || std::stod(token[3]) < 100.0 || std::stod(token[3]) > 1000.0)
		throw std::runtime_error("[ERROR] parsing: acceleration: " + token[3] + " is not a valid arguments; in file: " + _trainComposePath);
	
	if (!isFloat(token[4]) || std::stod(token[4]) < 5.0 || std::stod(token[4]) > 1000.0)
		throw std::runtime_error("[ERROR] parsing: brake: " + token[4] + " is not a valid arguments; in file: " + _trainComposePath);
	
	if (!isANode(token[5]))
		throw std::runtime_error("[ERROR] parsing: " + token[5] + " is not a departure station; in file: " + _trainComposePath);
	
	if (!isANode(token[6]))
		throw std::runtime_error("[ERROR] parsing: " + token[6] + " is not a arrival station; in file: " + _trainComposePath);
	
	if (token[5] == token[6])
		throw std::runtime_error("[ERROR] parsing: double: " + token[6] + " cannot be the departure and the arrival at the same time; in file: " + _trainComposePath);
	
	if (!isHours(token[7]))
		throw std::runtime_error("[ERROR] parsing: DeparturTime: " + token[7] + " is not a valid arguments; in file: " + _trainComposePath);
	
	if (!isHours(token[8]))
		throw std::runtime_error("[ERROR] parsing: StopTime: " + token[8] + " is not a valid arguments; in file: " + _trainComposePath);
	_trains.push_back(p_line);
}

void Parsing::trainComposeChecker() {
	std::string line;

	if (isemptyFile(_trainComposeFile))
		throw std::runtime_error("[ERROR] parsing: empty file: " + _trainComposePath);

	while (std::getline(*_trainComposeFile, line)) {
		trainChecker(line);
	}
}

bool Parsing::isFloat(std::string p_arg) {
	int i = 0;

	while (p_arg[i] && p_arg[i] != '.') {
		if (p_arg[i] < '0' || p_arg[i] > '9')
			return false;
		++i;
	}

	if (p_arg[i] != '.')
		return false;
	++i;

	while (p_arg[i]) {
		if (p_arg[i] < '0' || p_arg[i] > '9')
			return false;
		++i;
	}

	return true;
}

bool Parsing::isInt(std::string p_arg) {
	int i = 0;

	while (p_arg[i]) {
		if (p_arg[i] < '0' || p_arg[i] > '9')
			return false;
		++i;
	}

	return true;
}

bool Parsing::isHours(std::string p_arg) {
	int i = 0;

	while (p_arg[i] && p_arg[i] != 'h') {
		if (p_arg[i] < '0' || p_arg[i] > '9')
			return false;
		++i;
	}

	if (p_arg[i] != 'h' || i != 2)
		return false;
	++i;

	while (p_arg[i]) {
		if (p_arg[i] < '0' || p_arg[i] > '9')
			return false;
		++i;
	}

	if (i != 5)
		return false;

	int j = (p_arg[0] - '0') * 10 + (p_arg[1] - '0');
	int k = (p_arg[0] - '0') * 10 + (p_arg[1] - '0');

	if ((j < 0 || j > 23) && (k < 0 || k > 59))
		return false;

	return true;
}

bool Parsing::isemptyFile(std::ifstream* p_file) {
	return p_file->peek() == std::ifstream::traits_type::eof();
}

bool Parsing::isANode(std::string p_name) {
	for (std::vector<std::string>::iterator it = _nodes.begin(); it != _nodes.end(); ++it)
		if (p_name == (*it))
			return true;

	return false;
}

