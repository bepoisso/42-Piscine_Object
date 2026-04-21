#include <cstdlib>
#include <ctime>
#include <iostream>

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
	Professor professorRogue("M. Rogue");
	Professor professorGodwin("M. Godwin");
	professorRogue.setHeadmasterMediator(&headmaster);
	professorGodwin.setHeadmasterMediator(&headmaster);
	std::cout << "Professors: " << professorRogue.getName() << ", " << professorGodwin.getName() << std::endl;
	
	std::cout << "\n--- Creating students ---" << std::endl;
	Student studentOne("Harry Potter");
	Student studentTwo("Hermione Granger");
	Student studentThree("Ron Weasley");
	studentOne.setHeadmasterMediator(&headmaster);
	studentTwo.setHeadmasterMediator(&headmaster);
	studentThree.setHeadmasterMediator(&headmaster);
	std::cout << "Students: " << studentOne.getName() << ", " << studentTwo.getName() << ", " << studentThree.getName() << std::endl;


	std::cout << std::endl << std::endl;
	
	std::cout << "============================================" << std::endl;
	std::cout << "           Start school simulation" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "--- Launch work for professors & students | day:0 (Back to school) ---" << std::endl;
	std::cout  << "-Professor Rogue Task-" << std::endl;
	professorRogue.backToSchool();
	std::cout << std::endl << "-Professor Godwin Task-" << std::endl;
	professorGodwin.backToSchool();

	int day = 1;
	while (day <= 100) {
		std::cout << "\n--- Launch work for professors & students | day:" << day << " ---" << std::endl;
		std::cout << "-Student Harry Task-" << std::endl;
		studentOne.attendClass();
		std::cout << std::endl << "-Student Hermione Task-" << std::endl;
		studentTwo.attendClass();
		std::cout << std::endl << "-Student Ron Task-" << std::endl;
		studentThree.attendClass();
		std::cout << std::endl << "-Professor Rogue Task-" << std::endl;
		professorRogue.doClass();
		std::cout << std::endl << "-Professor Godwin Task-" << std::endl;
		professorGodwin.doClass();
		std::cout << "--- Day: " << day << " Finished ---" << std::endl << std::endl;
		day++;
	}

	std::cout << "\n============================================" << std::endl;
	std::cout << "           End of school simulation" << std::endl;
	std::cout << "============================================" << std::endl;

	return 0;
}

//TODO: le mediaton a redonner le cours graduer au student (a fix)

//TODO: verifier le nombre de place dans un cours et si non renvoyer dans un autre cours
