#include "Rail.hpp"

Rail::Rail(Node* p_departure, Node* p_arrival, float p_lenght, float p_speed) : _prevNode(p_departure), _nextNode(p_arrival), _lenght(p_lenght), _speedMax(p_speed) {
}

Rail::~Rail() {
}
