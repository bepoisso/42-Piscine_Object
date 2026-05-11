/**
 * @file Node.hpp
 * @brief Node class - Network vertex
 * 
 * @details
 * Represents a city or station with a name, station flag, and optional delay.
 * 
 * @note
 * principles Encapsulation
 */

#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Forward.hpp"

#include "Rail.hpp"
#include "Time.hpp"

class Rail;

class Node {
private:
	const std::string	_name;
	const bool			_isStation;

	Time				_delay;

public:
	Node(std::string p_name, bool p_station);
	~Node();

	const std::string getName() const { return _name; }
	bool isStation() const { return _isStation; }

	void setDelay(Time p_delay) { _delay = p_delay; }
	Time getDelay() const { return _delay; }
};
