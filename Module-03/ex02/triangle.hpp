#pragma once

#include <cmath>
#include "shape.hpp"

class Triangle : public Shape {
private:
	// Attributes
	double a;
	double b;
	double c;

	bool isValid() const {
		return (a > 0 && b > 0 && c > 0
			&& a + b > c
			&& a + c > b
			&& b + c > a);
	}

public:
	Triangle(double newA, double newB, double newC) : a(newA), b(newB), c(newC) {}
	virtual ~Triangle() {}

/* Operator */

/* Getter / Setter */

/* Methode */
	virtual double area() const {
		if (!isValid()) {
			return 0.0;
		}
		double x = (a + b + c) / 2.0;
		return std::sqrt(x * (x - a) * (x - b) * (x - c));
	}

	virtual double perimeter() const {
		if (!isValid()) {
			return 0.0;
		}
		return a + b + c;
	}

};
