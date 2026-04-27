#include "Headmaster.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "School.hpp"

#include <iostream>

Headmaster::Headmaster(std::string p_name, Secretary* newSecretary) : Staff(p_name, 3), _secretary(newSecretary) {
}

Headmaster::~Headmaster() {
	for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
		delete *it;
	_formToValidate.clear();
}

Form* Headmaster::requestForm(FormType p_formType) {
	if (!_secretary) {
		std::cout << printHeader() << getName() << " cannot request form: no secretary assigned" << std::endl;
		return NULL;
	}
	Form* form = _secretary->createForm(p_formType);
	if (!form) {
		std::cout << printHeader() << getName() << " failed to request form" << std::endl;
		return NULL;
	}
	receiveForm(form);
	return form;
}

void Headmaster::receiveForm(Form* p_form) {
	if (!p_form)
		return;
	if (hasReceivedForm(p_form))
		return;
	_formToValidate.push_back(p_form);
}

void Headmaster::submitForm(Form* p_form) {
	if (!p_form)
		return;
	receiveForm(p_form);
	signForm(p_form);
	executeForm(p_form);
	
}

bool Headmaster::hasReceivedForm(Form* p_form) const {
	for (std::vector<Form*>::const_iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it) {
		if (*it == p_form)
			return true;
	}
	return false;
}

void Headmaster::releaseForm(Form* p_form) {
	for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it) {
		if (*it == p_form) {
			_formToValidate.erase(it);
			return;
		}
	}
}

void	Headmaster::signForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << printHeader() << getName() << " refused to sign: form was not received" << std::endl;
		return;
	}
	if (!p_form->isComplete())
		return;
	p_form->setIsSigned(true);
}

void	Headmaster::executeForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << printHeader() << getName() << " refused to execute: form was not received" << std::endl;
		return;
	}
	p_form->execute();

	SecretarialOffice* secretarialOffice = static_cast<SecretarialOffice*>(_secretary->getCurrentRoom());
	secretarialOffice->archiveForms(p_form);
	releaseForm(p_form);
}

Classroom*	Headmaster::giveClassroomToProfessor() {
	std::vector<Classroom*> classroomsList = _school->getClassroomsList();
	for (std::vector<Classroom*>::iterator it = classroomsList.begin(); it != classroomsList.end(); ++it) {
		if ((*it)->getCurrentCourse() == NULL && (*it)->isEmpty())
			return *it;
	}
	return NULL;
}

Course* Headmaster::giveCourseToprofessor() { 
	std::vector<Course*> courseList = _school->getCoursesList();
	for (std::vector<Course*>::iterator it = courseList.begin(); it != courseList.end(); ++it) {
		if ((*it)->isStudentSubscribed() && (*it)->getResponsable() == NULL)
			return *it;
	}
	return NULL;
}

Classroom*		Headmaster::getClassroom() { 
	return _school->getClassroom();
}

Canteen*		Headmaster::getCanteen() { 
	return _school->getCanteen();
}

Courtyard*		Headmaster::getCourtyard() { 
	return _school->getCourtyard();
}

StaffRestRoom*	Headmaster::getStaffRestRoom() { 
	return _school->getStaffRestRoom();
}


Course*		Headmaster::giveNewCourseForStudent(Student* p_student) {
	std::vector<Course*> coursesList = _school->getCoursesList();
	for (std::vector<Course*>::iterator it = coursesList.begin(); it != coursesList.end(); ++it) {
		if (p_student->isGraduateCourse(*it) == false && (*it)->getMaximumNumberOfStudent() > (*it)->getNumberOfStudent())
			return *it;
	}
	return NULL;
}

const std::vector<Course*>	Headmaster::getCourseList() {
	return _school->getCoursesList();
}

Course*						Headmaster::getCourse(std::string p_name) {
	return _school->getCourse(p_name);
}


bool		Headmaster::checkIfCourseExist(std::string p_name) {
	if (p_name == "")
		return true;
	std::vector<Course*> coursesList = _school->getCoursesList();
	for (std::vector<Course*>::iterator it = coursesList.begin(); it != coursesList.end(); ++it) {
		if (p_name == (*it)->getName())
			return true;
	}
	return false;
}

void	Headmaster::professorDoWork() {
	std::vector<Professor*> list = _school->getProfessors();
	for(std::vector<Professor*>::iterator it = list.begin(); it != list.end(); ++it) {
		(*it)->doClass();
		std::cout << std::endl;
	}
}

void	Headmaster::studentDoWork() {
	std::vector<Student*> list = _school->getStudents();
	for(std::vector<Student*>::iterator it = list.begin(); it != list.end(); ++it) {
		(*it)->attendClass();
		std::cout << std::endl;
	}
}


void	Headmaster::subscribeBell(IObserver* obs) {
	if (!obs)
		return;
	
	for (std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it == obs)
				return;
		}
	_bellObservers.push_back(obs);
}

void	Headmaster::unsubscribeBell(IObserver	* obs) {
	if (!obs)
		return;

	for (std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it == obs) {
			_bellObservers.erase(it);
			return;
		}
	}
}

void Headmaster::ringBell() {
	std::cout << std::endl << printHeader() << getName() << " *RING RING RING*" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(RingBell);
	}
}

void Headmaster::lunchTime() {
	std::cout << std::endl << printHeader() << getName() << " *RING RING RING* *MIAM MIAM MIAM*" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(LunchTime);
	}
}

void Headmaster::coursesFinish() {
	std::cout << std::endl << printHeader() << getName() << " *RING RING RING* *Zzz Zzz Zzz" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(CoursesFinish);
	}
}

