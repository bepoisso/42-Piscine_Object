#include <iostream>
#include <vector>

#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "NeedCourseCreationForm.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedMoreClassRoomForm.hpp"

int main() {
	std::cout << "========== SCHOOL SIMULATION ==========" << std::endl << std::endl;

	// Create the headmaster (mediator)
	Headmaster headmaster("Mr. Headmaster");
	
	// Create the secretary
	Secretary secretary("Mrs. Secretary");
	headmaster.setSecretary(&secretary);

	// Create professors
	Professor prof1("Prof. John");
	Professor prof2("Prof. Jane");
	std::cout << "Professors created" << std::endl << std::endl;

	// Create students
	Student student1("Alice");
	Student student2("Bob");
	Student student3("Charlie");
	std::cout << "Students created" << std::endl << std::endl;

	// ===== CREATE COURSES DIRECTLY =====
	std::cout << "========== COURSE CREATION ==========" << std::endl;
	headmaster.createCourse("Mathematics");
	headmaster.createCourse("Physics");
	std::cout << std::endl;

	// ===== PROFESSOR ASSIGNMENT =====
	std::cout << "========== PROFESSOR ASSIGNMENT ==========" << std::endl;
	headmaster.teachCourse(&prof1);
	headmaster.teachCourse(&prof2);
	std::cout << std::endl;

	// ===== STUDENT SUBSCRIPTION =====
	std::cout << "========== STUDENT SUBSCRIPTION ==========" << std::endl;
	headmaster.attendCourse(&student1);
	headmaster.attendCourse(&student2);
	headmaster.attendCourse(&student3);
	std::cout << std::endl;

	// ===== REQUEST CLASSROOM =====
	std::cout << "========== CLASSROOM REQUEST ==========" << std::endl;
	headmaster.requestClassroom(&prof1);
	headmaster.requestClassroom(&prof2);
	std::cout << std::endl;

	// ===== TEACH SESSIONS =====
	std::cout << "========== TEACH SESSIONS ==========" << std::endl;
	if (prof1.getCurrentCourse()) {
		prof1.doClass();
		prof1.doClass();
		prof1.doClass();
	}
	
	if (prof2.getCurrentCourse()) {
		prof2.doClass();
		prof2.doClass();
		prof2.doClass();
	}
	std::cout << std::endl;

	// ===== GRADUATION =====
	std::cout << "========== GRADUATION ==========" << std::endl;
	if (student1.firstCourse()) {
		headmaster.graduateStudent(&student1, student1.firstCourse());
		student1.graduate(student1.firstCourse());
	}
	
	if (student2.firstCourse()) {
		headmaster.graduateStudent(&student2, student2.firstCourse());
		student2.graduate(student2.firstCourse());
	}
	
	if (student3.firstCourse()) {
		headmaster.graduateStudent(&student3, student3.firstCourse());
		student3.graduate(student3.firstCourse());
	}
	std::cout << std::endl;

	// ===== FORM-BASED INTERACTIONS =====
	std::cout << "========== FORM-BASED INTERACTIONS (Mediator Pattern) ==========" << std::endl;

	// Professor requests a new course
	std::cout << "\n--- Professor requests new course ---" << std::endl;
	NeedCourseCreationForm* courseForm = dynamic_cast<NeedCourseCreationForm*>(secretary.createForm(NeedCourseCreation));
	if (courseForm) {
		secretary.fillForm(courseForm, FormPayload("Chemistry", "Prof. Smith", "", 4));
		headmaster.receiveForm(courseForm);
		headmaster.signForm(courseForm);
		headmaster.executeForm(courseForm);
		delete courseForm;
	}

	// Student requests to join a course
	std::cout << "\n--- Student requests course subscription ---" << std::endl;
	SubscriptionToCourseForm* subForm = dynamic_cast<SubscriptionToCourseForm*>(secretary.createForm(SubscriptionToCourse));
	if (subForm) {
		secretary.fillForm(subForm, FormPayload("David", "Mathematics", "Semester 1", 0));
		headmaster.receiveForm(subForm);
		headmaster.signForm(subForm);
		headmaster.executeForm(subForm);
		delete subForm;
	}

	// Professor needs more classrooms
	std::cout << "\n--- Professor requests additional classrooms ---" << std::endl;
	NeedMoreClassRoomForm* roomForm = dynamic_cast<NeedMoreClassRoomForm*>(secretary.createForm(NeedMoreClassRoom));
	if (roomForm) {
		secretary.fillForm(roomForm, FormPayload("Prof. John", "Large class enrollment", "", 2));
		headmaster.receiveForm(roomForm);
		headmaster.signForm(roomForm);
		headmaster.executeForm(roomForm);
		delete roomForm;
	}

	// Graduation notification form
	std::cout << "\n--- Student graduation confirmation ---" << std::endl;
	CourseFinishedForm* gradForm = dynamic_cast<CourseFinishedForm*>(secretary.createForm(CourseFinished));
	if (gradForm) {
		secretary.fillForm(gradForm, FormPayload("Alice", "Mathematics", "", 95));
		headmaster.receiveForm(gradForm);
		headmaster.signForm(gradForm);
		headmaster.executeForm(gradForm);
		delete gradForm;
	}
	std::cout << std::endl;

	std::cout << "========== SIMULATION END ==========" << std::endl;
	return 0;
}
