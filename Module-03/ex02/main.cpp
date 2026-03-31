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
	std::vector<Shape*> shapes;
	shapes.push_back(new Rectangle(5.0, 3.0));
	shapes.push_back(new Circle(2.0));
	shapes.push_back(new Triangle(3.0, 4.0, 5.0));

	for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
		printShapeInfo(**it);
		delete *it;
	}
	return 0;
}
