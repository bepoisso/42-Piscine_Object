#include "Professor.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>

Professor::Professor(std::string p_name)
	: Staff(p_name), _currentCourse(NULL), _headmasterMediator(NULL) {
}

void Professor::setHeadmasterMediator(Headmaster* headmaster) {
	_headmasterMediator = headmaster;
	if (_headmasterMediator)
		_headmasterMediator->subscribeBell(this);
}

void Professor::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}

void Professor::doClass() {
	if (!_currentCourse)
		needNewCourse();
	Classroom* classroom = _currentCourse->getClassroom();
	if (!classroom) {
		classroom = _headmasterMediator->giveClassroomToProfessor();	
		if (!classroom)
			needMoreClassRoom();
		else {
			_currentCourse->setClassroom(classroom);
			classroom->assignCourse(_currentCourse);
		}
	}
	if (!classroom && !_currentCourse->getClassroom()) {
		std::cout << "\033[31m[ERROR] ITERNAL ERROR FAIL TO CREATE ROOM\033[0m" << std::endl;
		return;
	}
	
	_currentCourse->getClassroom()->enter(this);
	std::cout << "[Professor] " << getName() << " enter in classroom no " << _currentCourse->getClassroom()->getID() << std::endl;
	std::cout << "[Professor] " << getName() << " do class of " << _currentCourse->getName() << " in classroom no " << _currentCourse->getClassroom()->getID() << std::endl;
	std::vector<Student*> studentsList = _currentCourse->getStudents();
	int i = 0;
	for (std::vector<Student*>::iterator it = studentsList.begin(); it != studentsList.end(); ++it) {
		if (_currentCourse->getClassroom()->isPresent(*it))
			i++;
	}
	if (i != 0) {
		for (std::vector<Student*>::iterator it = studentsList.begin(); it != studentsList.end(); ++it) {
			if (_currentCourse->getClassroom()->isPresent(*it))
				(*it)->receiveLesson(_currentCourse);
			else
				std::cout << "Student " << (*it)->getName() << " was not present!" << std::endl;
		}
	}
	closeCourse();
}

void Professor::closeCourse() {
	if (!_currentCourse)
		return;
	std::cout << "[Professor] " << getName() << " as finish course " << _currentCourse->getName() << std::endl;
	std::vector<Student*> studentsList = _currentCourse->getStudents();

	for (size_t i = 0; i < studentsList.size(); ++i) {
		if (studentsList[i]->getCurrentScore(_currentCourse) >= _currentCourse->getNumberOfClassToGraduate()) {
			std::cout << "[DEBUG] professor " << getName() << " want to graduate " << studentsList[i]->getName() << " Note : " <<  studentsList[i]->getCurrentScore(_currentCourse) << "/" << _currentCourse->getNumberOfClassToGraduate() << std::endl;
			needGraduateStudent(studentsList[i]);
		}
		if (getCurrentRoom()->isPresent(studentsList[i]))
			studentsList[i]->exitClass();
	}
	std::cout << "[Professor] " << getName() << " exit classroom " << getCurrentRoom()->getID() << std::endl;
	getCurrentRoom()->exit(this);

}

void Professor::needGraduateStudent(Student* student) {
	std::cout << "[Professor] " << getName() << " request CourseFinishedForm (GraduateForm)" << std::endl;
	if (!_headmasterMediator || !student) {
		std::cout << "\033[31m[ERROR] Professor cannot request graduation: invalid mediator or student\033[0m" << std::endl;
		return;
	}
	if (!_currentCourse) {
		std::cout << "\033[31m[ERROR] Professor cannot request graduation: no assigned course\033[0m" << std::endl;
		return;
	}

	Form* form = _headmasterMediator->requestForm(CourseFinished);
	CourseFinishedForm* graduateForm = dynamic_cast<CourseFinishedForm*>(form);
	if (!graduateForm) {
		std::cout << "\033[31m[ERROR] Professor cannot request graduation: wrong form type received\033[0m" << std::endl;
		return;
	}

	graduateForm->fillCourseResult(student, _currentCourse, student->getCurrentScore(_currentCourse));
	_headmasterMediator->submitForm(graduateForm);
}

void Professor::needNewCourse() {
	std::cout << "[Professor] " << getName() << " request NeedCourseCreationForm" << std::endl;
	std::string courseName = "";
	if (!_headmasterMediator) {
		std::cout << "\033[31m[ERROR] Professor cannot request new course: no mediator\033[0m" << std::endl;
		return;
	}
	Form* form = _headmasterMediator->requestForm(NeedCourseCreation);
	if (!form) {
		std::cout << "\033[31m[ERROR] Professor cannot request new course: form unavailable\033[0m" << std::endl;
		return;
	}
	NeedCourseCreationForm* courseForm = dynamic_cast<NeedCourseCreationForm*>(form);

	int i = 10;
	while (i > 0 && (courseName == "" || _headmasterMediator->checkisCourseExist(courseName))) {
		switch (std::rand() % 20 + 1) {
			case 1:  courseName = "Algorithms"; break;
			case 2:  courseName = "Database Design"; break;
			case 3:  courseName = "Operating Systems"; break;
			case 4:  courseName = "Web Development"; break;
			case 5:  courseName = "Computer Networks"; break;
			case 6:  courseName = "Data Structures"; break;
			case 7:  courseName = "Object-Oriented Programming"; break;
			case 8:  courseName = "Software Engineering"; break;
			case 9:  courseName = "Distributed Systems"; break;
			case 10: courseName = "Compilers"; break;
			case 11: courseName = "Machine Learning"; break;
			case 12: courseName = "Artificial Intelligence"; break;
			case 13: courseName = "Cybersecurity"; break;
			case 14: courseName = "Cloud Computing"; break;
			case 15: courseName = "DevOps"; break;
			case 16: courseName = "Computer Architecture"; break;
			case 17: courseName = "Parallel Programming"; break;
			case 18: courseName = "Theory of Computation"; break;
			case 19: courseName = "Human-Computer Interaction"; break;
			default: courseName = "Mobile Development"; break;
		}
		i--;
	}
	int temp = (rand() % 10 + 2);

	courseForm->fillCoursePlan(courseName, this, temp);
	_headmasterMediator->submitForm(courseForm);
}

void Professor::needMoreClassRoom() {
	std::cout << "[Professor] " << getName() << " request needMoreClassRoom" << std::endl;
	if (!_headmasterMediator) {
		std::cout << "\033[31m[ERROR] Professor cannot request new classroom: no mediator\033[0m" << std::endl;
		return;
	}
	Form* form = _headmasterMediator->requestForm(NeedMoreClassRoom);
	if (!form) {
		std::cout << "\033[31m[ERROR] Professor cannot request new classroom: form unavailable\033[0m" << std::endl;
		return;
	}

	NeedMoreClassRoomForm* classroomForm = dynamic_cast<NeedMoreClassRoomForm*>(form);
	classroomForm->fillRequest(this, "No empty classroom found", 1);
	_headmasterMediator->submitForm(classroomForm);
}

void Professor::onBell(Event event) {
	if (event != RingBell)
		return;
	_isOnBreak = !_isOnBreak;
	if (_isOnBreak)
		if (getCurrentRoom())
			getCurrentRoom()->exit(this);
}
