#pragma once

#include "Forward.hpp"

class Rail
{
private:
	const Node*		_prevNode;
	const Node*		_nextNode;
	const float		_lenght;
	const float		_speedMax;

public:
	Rail(Node* p_departure, Node* p_arrival, float p_lenght, float p_speed);
	~Rail();

	const Node* getprevNode() const { return _prevNode; }
	const Node* getNextNode() const { return _nextNode; }
	const float getLenght() const { return _lenght; }
	const float getSpeedMax() const { return _speedMax; }
};
