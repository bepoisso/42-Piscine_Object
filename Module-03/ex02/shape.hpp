#pragma once

class Shape {
public:
	// Canonical Form
	Shape() {}
	virtual ~Shape() {}
	Shape(const Shape &other) {
		(void)other;
	}
	Shape &operator=(const Shape &other) {
		(void)other;
		return *this;
	}

/* Methode */
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

};
