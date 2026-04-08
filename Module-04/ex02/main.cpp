#include "Form.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "CourseFinishedForm.hpp"

#include <string>
#include <iostream>

int main (void) {
	Secretary secretary("Alice");
	Headmaster headmaster("Bob");

	Form* subscription = secretary.createForm(SubscriptionToCourse);
	Form* classroomNeed = secretary.createForm(NeedMoreClassRoom);
	Form* courseCreation = secretary.createForm(NeedCourseCreation);
	Form* courseFinished = secretary.createForm(CourseFinished);
	Form* notReceived = secretary.createForm(SubscriptionToCourse);
	Form* receivedButUnsigned = secretary.createForm(NeedCourseCreation);

	secretary.fillForm(subscription, FormPayload("Leo", "Modern C++", "S2-2026"));
	secretary.fillForm(classroomNeed, FormPayload("Pedagogy Team", "Student number increased", "", 2));
	secretary.fillForm(courseCreation, FormPayload("Algorithms", "Pr. Turing", "", 6));
	secretary.fillForm(courseFinished, FormPayload("Leo", "Modern C++", "", 17));
	secretary.fillForm(receivedButUnsigned, FormPayload("Databases", "Pr. Codd", "", 4));

	std::cout << "--- Try sign/execute form not received by headmaster ---" << std::endl;
	headmaster.signForm(notReceived);
	headmaster.executeForm(notReceived);

	std::cout << "--- Try execute received but unsigned form ---" << std::endl;
	headmaster.receiveForm(receivedButUnsigned);
	headmaster.executeForm(receivedButUnsigned);

	headmaster.receiveForm(subscription);
	headmaster.receiveForm(classroomNeed);
	headmaster.receiveForm(courseCreation);
	headmaster.receiveForm(courseFinished);

	headmaster.signForm(subscription);
	headmaster.signForm(classroomNeed);
	headmaster.signForm(courseCreation);
	headmaster.signForm(courseFinished);

	std::cout << "--- Execute signed forms ---" << std::endl;
	headmaster.executeForm(subscription);
	headmaster.executeForm(classroomNeed);
	headmaster.executeForm(courseCreation);
	headmaster.executeForm(courseFinished);

	delete subscription;
	delete classroomNeed;
	delete courseCreation;
	delete courseFinished;
	delete notReceived;
	delete receivedButUnsigned;


	return 0;
}
