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

static void submitForm(Headmaster& headmaster, Secretary& secretary, FormType type, const FormPayload& payload)
{
	Form* form = headmaster.requestForm(type);
	secretary.fillForm(form, payload);
	headmaster.submitForm(form);
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== Module 04 - Ex03 demo ===" << std::endl;

	Secretary secretary("Ms. Handerson");
	Headmaster headmaster("Mr. Dumbuldor", &secretary);

	Professor professor("Professor Rigue");
	Student studentOne("Justine");
	Student studentTwo("Antoine");
	professor.setHeadmasterMediator(&headmaster);
	studentOne.setHeadmasterMediator(&headmaster);
	studentTwo.setHeadmasterMediator(&headmaster);

	Course cppCourse("C++ Basics");
	Classroom mainClassroom;

	std::cout << "\n--- Manual school setup ---" << std::endl;
	professor.assignCourse(&cppCourse);
	cppCourse.assign(&professor);
	mainClassroom.assignCourse(&cppCourse);

	std::cout << "Course: " << cppCourse.getName() << std::endl;
	std::cout << "Professor: " << professor.getName() << std::endl;
	std::cout << "Students: " << studentOne.getName() << ", " << studentTwo.getName() << std::endl;

	std::cout << "\n--- Students join the classroom ---" << std::endl;
	studentOne.attendClass(&mainClassroom);
	studentTwo.attendClass(&mainClassroom);
	mainClassroom.printOccupant();

	std::cout << "\n--- Course subscription list ---" << std::endl;
	cppCourse.subscribe(&studentOne);
	cppCourse.subscribe(&studentTwo);

	std::cout << "\n--- Professor teaches one class ---" << std::endl;
	std::cout << "Before class: " << studentOne.getName() << " score = " << studentOne.getCurrentScore() << std::endl;
	std::cout << "Before class: " << studentTwo.getName() << " score = " << studentTwo.getCurrentScore() << std::endl;
	professor.doClass();
	std::cout << "After class: " << studentOne.getName() << " score = " << studentOne.getCurrentScore() << std::endl;
	std::cout << "After class: " << studentTwo.getName() << " score = " << studentTwo.getCurrentScore() << std::endl;

	std::cout << "\n--- Students leave the classroom ---" << std::endl;
	studentOne.exitClass();
	studentTwo.exitClass();
	mainClassroom.printOccupant();

	std::cout << "\n--- Secretary / Headmaster form workflow ---" << std::endl;

	submitForm(headmaster, secretary, NeedCourseCreation,
		FormPayload(NULL, &cppCourse, &professor, "", "", "Spring 2026", 4));

	submitForm(headmaster, secretary, SubscriptionToCourse,
		FormPayload(&studentOne, &cppCourse, &professor, "", "", "Fall 2026", 0));

	submitForm(headmaster, secretary, NeedMoreClassRoom,
		FormPayload(NULL, NULL, &professor, "No empty room available", "", "", 1));

	submitForm(headmaster, secretary, CourseFinished,
		FormPayload(&studentOne, &cppCourse, &professor, "", "", "", 100));

	std::cout << "\n--- End of demo ---" << std::endl;
	return 0;
}

