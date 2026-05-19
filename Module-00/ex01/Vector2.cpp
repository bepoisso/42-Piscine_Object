#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {
}

Vector2::~Vector2() {
}

float Vector2::getX() const { 
	return x;

}
float Vector2::getY() const {
	return y;
}
