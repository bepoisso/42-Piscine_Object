#pragma once

#define _PI 3.14159265358979323846

#include "shape.hpp"

class Circle : public Shape {
private:
	// Attributes
	double radius;

public:
	// Canonical Form
	Circle(double newRadius) : radius(newRadius < 0 ? 0 : newRadius) {}
	virtual ~Circle() {}
	Circle(const Circle &other) : Shape(other), radius(other.radius) {}
	Circle &operator=(const Circle &other) {
		if (this != &other) {
			radius = other.radius;
		}
		return *this;
	}

/* Operator */

/* Getter / Setter */

/* Methode */
	virtual double area() const { return _PI * radius * radius; }
	virtual double perimeter() const { return 2.0 * _PI * radius; }

};
