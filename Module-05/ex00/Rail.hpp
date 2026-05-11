/**
 * @file Rail.hpp
 * @brief Rail class - Connection between nodes
 * 
 * @details
 * Represents a rail segment with length, speed limits, and temporary
 * constraints such as blocking or limitation speed.
 * 
 * @note
 * principles Encapsulation
 */

#pragma once

#include <iostream>

#include "Forward.hpp"

#include "Node.hpp"


class Node;

class Rail {
private:
	const Node*				_prevNode;
	const Node*				_nextNode;
	const double			_lenght;		//	km -> m
	const double			_speedMax;		//	km/h -> m/s

	bool					_blocked;
	double					_limitationSpeed; //	m/s

public:
	Rail(Node* p_departure, Node* p_arrival, double p_lenght, double p_speed);
	~Rail();

	Node* getPrevNode() const { return const_cast<Node*>(_prevNode); }
	Node* getNextNode() const { return const_cast<Node*>(_nextNode); }
	double getLenght() const { return _lenght; }
	double getSpeedMax() const;

	void setBlocked(bool p) { _blocked = p; };
	bool isBlocked() const { return _blocked; }
	void setLimitationSpeed(double p_speed) { _limitationSpeed = p_speed; }
	double getLimitationSpeed() const { return _limitationSpeed; }

};

std::ostream& operator<<(std::ostream& os, const Rail& rail);
