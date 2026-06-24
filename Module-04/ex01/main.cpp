#include <iostream>
#include <string>

#include "CourseList.hpp"
#include "RoomList.hpp"
#include "StaffList.hpp"
#include "StudentList.hpp"

class Student
{
public:
	explicit Student(const std::string& p_name) : _name(p_name) {}
	std::string _name;
};

class Staff
{
public:
	explicit Staff(const std::string& p_name) : _name(p_name) {}
	std::string _name;
};

class Course
{
public:
	explicit Course(const std::string& p_name) : _name(p_name) {}
	std::string _name;
};

class Room
{
public:
	explicit Room(const std::string& p_name) : _name(p_name) {}
	std::string _name;
};

void AExternalFunction() {
	Student victor("Victor");
	Student jack("Jack");
	Staff profB("Professor B");
	Course Algorithm("Algorithm");
	Room c418("C418");

	StudentList::getInstance().add(&victor);
	StudentList::getInstance().add(&jack);
	StaffList::getInstance().add(&profB);
	CourseList::getInstance().add(&Algorithm);
	RoomList::getInstance().add(&c418);
}

int main()
{
	Student alice("Alice");
	Student bob("Bob");
	Staff profX("Professor X");
	Course cpp("C++ Design Patterns");
	Room b404("B404");

	StudentList::getInstance().add(&alice);
	StudentList::getInstance().add(&bob);
	StaffList::getInstance().add(&profX);
	CourseList::getInstance().add(&cpp);
	RoomList::getInstance().add(&b404);

	std::cout << "Students count: " << StudentList::getInstance().size() << std::endl;
	std::cout << "Staff count: " << StaffList::getInstance().size() << std::endl;
	std::cout << "Courses count: " << CourseList::getInstance().size() << std::endl;
	std::cout << "Rooms count: " << RoomList::getInstance().size() << std::endl;
	std::cout << "----------" << std::endl;

	AExternalFunction();

	std::cout << "Students count: " << StudentList::getInstance().size() << std::endl;
	std::cout << "Staff count: " << StaffList::getInstance().size() << std::endl;
	std::cout << "Courses count: " << CourseList::getInstance().size() << std::endl;
	std::cout << "Rooms count: " << RoomList::getInstance().size() << std::endl;

	Student* firstStudent = 0;
	if (StudentList::getInstance().get(0, firstStudent) && firstStudent != 0)
		std::cout << "First student: " << firstStudent->_name << std::endl;

	return 0;
}
