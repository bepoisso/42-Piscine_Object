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

int main()
{
	Student alice("Alice");
	Student bob("Bob");
	Staff profX("Professor X");
	Course cpp("C++ Design Patterns");
	Room b12("B404");

	StudentList::getInstance().add(&alice);
	StudentList::getInstance().add(&bob);
	StaffList::getInstance().add(&profX);
	CourseList::getInstance().add(&cpp);
	RoomList::getInstance().add(&b12);

	std::cout << "Students count: " << StudentList::getInstance().size() << '\n';
	std::cout << "Staff count: " << StaffList::getInstance().size() << '\n';
	std::cout << "Courses count: " << CourseList::getInstance().size() << '\n';
	std::cout << "Rooms count: " << RoomList::getInstance().size() << '\n';

	Student* firstStudent = 0;
	if (StudentList::getInstance().get(0, firstStudent) && firstStudent != 0)
		std::cout << "First student: " << firstStudent->_name << '\n';

	return 0;
}
