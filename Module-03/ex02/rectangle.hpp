#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
private:
	double width;
	double height;

public:
	Rectangle(double newWidth, double newHeight) : width( newWidth < 0 ? 0 : newWidth), height( newHeight < 0 ? 0 : newHeight) {} 
	virtual ~Rectangle() {}

/* Methode */
	virtual double area() const { return width * height; }
	virtual double perimeter() const {return 2.0 * (width + height); }

};
