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

public:
	Rail(Node* p_departure, Node* p_arrival, double p_lenght, double p_speed);
	~Rail();

	Node* getPrevNode() const { return const_cast<Node*>(_prevNode); }
	Node* getNextNode() const { return const_cast<Node*>(_nextNode); }
	double getLenght() const { return _lenght; }
	double getSpeedMax() const { return _speedMax; }
};

std::ostream& operator<<(std::ostream& os, const Rail& rail);
