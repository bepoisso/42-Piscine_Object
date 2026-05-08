#include "Time.hpp"


Time::Time() : _time(0) {
}

Time::Time(long int p_time) : _time(p_time) {
}

Time::Time(const std::string& str) {
	_time = StoLI(str);
}


Time::~Time() {
}

long int Time::StoLI(std::string str) {
	if (str.size() != 5 || str[2] != 'h')
		throw std::invalid_argument("Invalid time format");

	long int hours = std::stoi(str.substr(0, 2));
	long int minutes = std::stoi(str.substr(3, 2));

	return ((hours * 60) + minutes) * 60;
}

std::string Time::ILtoS(long int p_time) const {
	long int total_minutes = p_time / 60;
	long int hours = total_minutes / 60;
	long int minutes = total_minutes % 60;
	std::string result;

	result += (hours / 10) + '0';
	result += (hours % 10) + '0';
	result += 'h';
	result += (minutes / 10) + '0';
	result += (minutes % 10) + '0';

	return result;
}

Time Time::operator+(long int p_time) const {
	return Time(_time + p_time);
}

Time Time::operator-(long int p_time) const {
	return Time(_time - p_time);
}

Time Time::operator%(long int p_time) const {
	return Time(_time % p_time);
}

long int Time::operator-(const Time& other) const {
	return _time - other._time;
}

bool Time::operator<(const Time& other) const {
	return _time < other._time;
}

bool Time::operator>(const Time& other) const {
	return _time > other._time;
}

bool Time::operator>=(const Time& other) const {
	return _time >= other._time;
}

bool Time::operator<=(const Time& other) const {
	return _time <= other._time;
}

bool Time::operator==(const Time& other) const {
	return _time == other._time;
}

bool Time::operator!=(const Time& other) const {
	return _time != other._time;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
	os << time.getTimeToS();
	return os;
}
