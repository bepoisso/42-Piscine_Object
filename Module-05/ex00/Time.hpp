/**
 * @file Time.hpp
 * @brief Time class - Time value object
 * 
 * @details
 * Stores time in seconds and provides formatting and arithmetic operators.
 * 
 * @note
 * principles Encapsulation
 */

#pragma once

#include <string>
#include <iostream>

class Time {
private:
	long int _time;

	long int StoLI(std::string str);
	std::string ILtoS(long int p_time) const;
public:
	Time();
	Time(long int p_time);
	Time(const std::string& str);
	~Time();

	long int getTime() const { return _time; }
	std::string getTimeToS() const { return ILtoS(_time % 86400); }

	// Operator
	Time operator+(long int p_time) const;
	Time operator-(long int p_time) const;
	Time operator%(long int p_time) const;
	long int operator-(const Time& other) const;
	bool operator<(const Time& other) const;
	bool operator>(const Time& other) const;
	bool operator<=(const Time& other) const;
	bool operator>=(const Time& other) const;
	bool operator==(const Time& other) const;
	bool operator!=(const Time& other) const;
};

std::ostream& operator<<(std::ostream& os, const Time& time);
