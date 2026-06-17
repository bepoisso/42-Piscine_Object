#include <iostream>
#include <vector>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

static void printShapeInfo(const Shape& s) {
	std::cout << "Area: " << s.area() << " | Perimeter: " << s.perimeter() << std::endl;
}

int main() {
	Rectangle	r(5.0, 3.0);
	Circle		c(2.0);
	Triangle	t(3.0, 4.0, 5.0);

	printShapeInfo(r);
	printShapeInfo(c);
	printShapeInfo(t);
	return 0;
}
