#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
private:
	double width;
	double height;

public:
	// Canonical Form
	Rectangle(double newWidth, double newHeight) : width( newWidth < 0 ? 0 : newWidth), height( newHeight < 0 ? 0 : newHeight) {} 
	virtual ~Rectangle() {}
	Rectangle(const Rectangle &other) : Shape(other), width(other.width), height(other.height) {}
	Rectangle& operator=(const Rectangle &other) {
		if (this != &other) {
			width = other.width;
			height = other.height;
		}
		return *this;
	}

/* Methode */
	virtual double area() const { return width * height; }
	virtual double perimeter() const {return 2.0 * (width + height); }

};
