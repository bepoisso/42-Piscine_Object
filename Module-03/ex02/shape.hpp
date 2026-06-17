#pragma once

class Shape {
public:
	Shape() {}
	virtual ~Shape() {}

/* Methode */
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

};
