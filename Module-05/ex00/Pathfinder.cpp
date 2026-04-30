#include "Pathfinder.hpp"


Pathfinder::Pathfinder(std::vector<Node*> p_nodes, std::vector<Rail*> p_rails, std::vector<Train*> p_trains) : _nodes(p_nodes), _rails(p_rails), _trains(p_trains) {

}

Pathfinder::~Pathfinder() {

}

std::vector<APosition*> Pathfinder::findOptimalPath(Train* p_train) {

}
