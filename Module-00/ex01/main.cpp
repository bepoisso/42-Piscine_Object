// Squelette de test pour Graph et Vector2
#include <iostream>
#include "Graph.hpp"
#include "Vector2.hpp"

int main() {
	Graph graph(6, 6);
	graph.addPoint(Vector2(0, 0));
	graph.addPoint(Vector2(2, 2));
	graph.addPoint(Vector2(4, 2));
	graph.addPoint(Vector2(2, 4));
	graph.draw();
	return 0;
}
