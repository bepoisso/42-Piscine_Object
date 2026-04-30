#pragma once

#include <iostream>

#include "Forward.hpp"

#include "Node.hpp"

class Node;

class Rail : public APosition {
private:
	const Node*				_prevNode;
	const Node*				_nextNode;
	const double			_lenght;
	const double			_speedMax;

public:
	Rail(Node* p_departure, Node* p_arrival, double p_lenght, double p_speed);
	~Rail();

	const Node* getprevNode() const { return _prevNode; }
	const Node* getNextNode() const { return _nextNode; }
	double getLenght() const { return _lenght; }
	double getSpeedMax() const { return _speedMax; }
};

std::ostream& operator<<(std::ostream& os, const Rail& rail);
