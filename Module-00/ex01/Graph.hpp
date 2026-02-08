#pragma once

#include <vector>
#include "Vector2.hpp"

class Graph {

private:
	Vector2 size;
	std::vector<Vector2> points;

public:
	Graph(float width, float height);
	~Graph();
	void addPoint(const Vector2& point);
	const Vector2& getSize() const;
	const std::vector<Vector2>& getPoints() const;
	void draw() const;

};
