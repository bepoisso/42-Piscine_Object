#include "Professor.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>

Professor::Professor(std::string p_name)
	: Staff(p_name, 1), _currentCourse(NULL), _headmasterMediator(NULL) {
}

void Professor::setHeadmasterMediator(Headmaster* headmaster) {
	_headmasterMediator = headmaster;
	if (_headmasterMediator)
		_headmasterMediator->subscribeBell(this);
}

bool Professor::initCourse() {
	if (!_currentCourse)
		needNewCourse();
	
	if (!_currentCourse) {
		std::cout << printHeader() << getName() << ": all done bye!" << std::endl;
		return false;
	}
	
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
		return false;
	}
	return true;
}

void Professor::assignCourse(Course* p_course) {
	_currentCourse = p_course;
}

void Professor::doClass() {
	closeCourse();
	if (!initCourse())
		return;
	_currentCourse->getClassroom()->enter(this);
	_isOnBreak = false;
	std::vector<Student*> studentsList = _currentCourse->getStudents();
	int i = 0;
	for (std::vector<Student*>::iterator it = studentsList.begin(); it != studentsList.end(); ++it) {
		if (_currentCourse->getClassroom()->isPresent(*it))
			i++;
	}
	if (i != 0) {
		std::cout << printHeader()  << getName() << " do class of " << _currentCourse->getName() << " in classroom no " << _currentCourse->getClassroom()->getID() << std::endl;
		for (std::vector<Student*>::iterator it = studentsList.begin(); it != studentsList.end(); ++it) {
			if (_currentCourse->getClassroom()->isPresent(*it))
				(*it)->receiveLesson(_currentCourse);
		}
	}
	else
		std::cout << printHeader()  << getName() << " don't do class. Reason : nobody in class" << std::endl;
}

void Professor::finishCourse() {
	if (!_currentCourse)
		return;
	std::cout << printHeader()  << getName() << " as finish course " << _currentCourse->getName() << std::endl;
	std::vector<Student*> studentsList = _currentCourse->getStudents();

	for (size_t i = 0; i < studentsList.size(); ++i) {
		if (studentsList[i]->getCurrentScore(_currentCourse) >= _currentCourse->getNumberOfClassToGraduate())
			needGraduateStudent(studentsList[i]);
	}
}

void Professor::closeCourse() {
	if (!_currentCourse)
		return;
	std::vector<Student*> studentsList = _currentCourse->getStudents();
	int i = 0;
	
	for (std::vector<Student*>::iterator it = studentsList.begin(); it != studentsList.end(); ++it) {
		i++;
	}
	if (i == 0) {
		std::cout << printHeader()  << getName() << " close course " << _currentCourse->getName() << std::endl;
		if (getCurrentRoom() == _currentCourse->getClassroom())
			getCurrentRoom()->exit(this);
		_currentCourse->getClassroom()->assignCourse(NULL);
		_currentCourse->setClassroom(NULL);
		_currentCourse = NULL;
	}
}

void Professor::needGraduateStudent(Student* student) {
	std::cout << printHeader()  << getName() << " request CourseFinishedForm (GraduateForm)" << std::endl;
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
	std::cout << printHeader()  << getName() << " request NeedCourseCreationForm" << std::endl;
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
	
	static const char* courseList[] = {
		"Algorithms",
		"Database Design",
		"Operating Systems",
		"Web Development",
		"Computer Networks",
		"Data Structures",
		"Object-Oriented Programming",
		"Software Engineering",
		"Distributed Systems",
		"Compilers",
		"Machine Learning",
		"Artificial Intelligence",
		"Cybersecurity",
		"Cloud Computing",
		"DevOps",
		"Computer Architecture",
		"Parallel Programming",
		"Theory of Computation",
		"Human-Computer Interaction",
		"Mobile Development",
	};

	const int count = sizeof(courseList) / sizeof(courseList[0]);
	std::string courseName = "";

	for (int i = 0; i < count; ++i) {
		if (!_headmasterMediator->checkIfCourseExist(courseList[i])) {
			courseName = courseList[i];
			break;
		}
	}

	int hours = (rand() % 10 + 2);
	courseForm->fillCoursePlan(courseName, this, hours);
	_headmasterMediator->submitForm(courseForm);
}

void Professor::needMoreClassRoom() {
	std::cout << printHeader() << getName() << " request needMoreClassRoom" << std::endl;
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
	if (event == RingBell) {
		_isOnBreak = !_isOnBreak;
		if (_isOnBreak) {
			safeExit();
			_headmasterMediator->getStaffRestRoom()->enter(this);
		} else {
			safeExit();
			doClass();
		}
	}
	else if (event == LunchTime) {
		_isOnBreak = true;
		safeExit();
		_headmasterMediator->getCanteen()->enter(this);
		std::cout << printHeader() << getName() << " eating a lot in the cafeteria" << std::endl; 
	} else if (event == CoursesFinish) {
		_isOnBreak = true;
		finishCourse();
		safeExit();
	} else {
		std::cout << "[ERROR] " << getName() << " received a bad event" << std::endl;
	}
}
