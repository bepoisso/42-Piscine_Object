#include <iostream>
#include "Graph.hpp"

Graph::Graph(float width, float height) : size(width, height) {}

Graph::~Graph() {}

void Graph::addPoint(const Vector2& point) {
	points.push_back(point);
}

const Vector2& Graph::getSize() const {
	return size;
}

const std::vector<Vector2>& Graph::getPoints() const {
	return points;
}

void Graph::draw() const {
	for (int y = size.getY() - 1; y >= 0; --y) {
		std::cout << y << " ";
		for (int x = 0; x < size.getX(); ++x) {
			bool found = false;
			for (size_t i = 0; i < points.size(); ++i) {
				if ((int)points[i].getX() == x && (int)points[i].getY() == y)
					found = true;
				if (found)
					std::cout << "X";
				else
					std::cout << ".";
			}
			std::cout << std::endl;
		}
		std::cout << "  ";
		for (int x = 0; x < size.getX(); ++x)
			std::cout << x << " ";
		std::cout << std::endl;
	}
}
