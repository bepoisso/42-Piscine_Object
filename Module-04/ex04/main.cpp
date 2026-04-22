#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>


#include "Classroom.hpp"
#include "Course.hpp"
#include "CourseFinishedForm.hpp"
#include "Headmaster.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "Professor.hpp"
#include "Secretary.hpp"
#include "Student.hpp"
#include "SubscriptionToCourseForm.hpp"

static std::string intToString(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "============================================" << std::endl;
	std::cout << "   Module 04 - Ex03 : School Management" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "\n--- Initializing school staff and mediator ---" << std::endl;
	Secretary secretary("Ms. Handerson");
	Headmaster headmaster("Mr. Dumbledore", &secretary);

	std::cout << "Secretary: " << secretary.getName() << std::endl;
	std::cout << "Headmaster: " << headmaster.getName() << std::endl;

	// ===== STAFF SETUP =====
	std::cout << "\n--- Creating professors ---" << std::endl;

	std::string pname = "Prof ";
	std::map<int, Professor> professors;

	for (int i = 0; i < 3; ++i) {
		Professor p(pname + intToString(i));
		p.setHeadmasterMediator(&headmaster);
		professors.insert(std::make_pair(i, p));
		std::cout << p.getName() << std::endl;
	}
	
	std::cout << "\n--- Creating students ---" << std::endl;

	std::string sname = "Stud ";
	std::map<int, Student> students;

	for (int i = 0; i < 10; ++i) {
		Student s(sname + intToString(i));
		s.setHeadmasterMediator(&headmaster);
		students.insert(std::make_pair(i, s));
		std::cout << s.getName() << std::endl;
	}

	std::cout << std::endl << std::endl;
	
	std::cout << "============================================" << std::endl;
	std::cout << "           Start school simulation" << std::endl;
	std::cout << "============================================" << std::endl;

	int day = 1;
	while (day <= 20) {
		std::cout << "\n--- Launch work for professors & students | day:" << day << " ---" << std::endl;

		std::cout << "--Professors Task--" << std::endl;
		for (std::map<int, Professor>::iterator it = professors.begin(); it != professors.end(); ++it) {
			std::cout << std::endl << "-Professor " << it->second.getName() << " Task-" << std::endl;
			it->second.doClass();
		}

		std::cout << "--Students Task--" << std::endl;
		for (std::map<int, Student>::iterator it = students.begin(); it != students.end(); ++it) {
			std::cout << std::endl << "-Student " << it->second.getName() << " Task-" << std::endl;
			it->second.attendClass();
		}
		// std::this_thread::sleep_for(std::chrono::seconds(1));
		day++;
	}

	std::cout << "\n============================================" << std::endl;
	std::cout << "           End of school simulation" << std::endl;
	std::cout << "============================================" << std::endl;

	return 0;
}
