#include "Headmaster.hpp"
#include "Form.hpp"
#include "Secretary.hpp"

#include <iostream>

Headmaster::~Headmaster() {
	for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
		delete *it;
	_formToValidate.clear();
}

Headmaster::Headmaster(std::string p_name, Secretary* newSecretary) : Staff(p_name, 3), _secretary(newSecretary) {
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
			delete *it;
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
	if (!p_form->isComplete()) {
		std::cout << printHeader() << getName() << " refused to sign: mandatory form data is missing" << std::endl;
		return;
	}
	std::cout << printHeader() << getName() << " signed form " << p_form->getFormName() << std::endl;
	p_form->setIsSigned(true);
	_secretary->archiveForm(p_form);
	releaseForm(p_form);
	
}

void	Headmaster::executeForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << printHeader() << getName() << " refused to execute: form was not received" << std::endl;
		return;
	}
	if (!p_form->getIsSigned()) {
		std::cout << printHeader() << getName() << " refused to execute: form not signed" << std::endl;
		return;
	}
	std::cout << printHeader() << getName() << " execute form " << p_form->getFormName() << std::endl;
	p_form->execute();
}

Classroom*	Headmaster::giveClassroomToProfessor() {
	std::vector<Classroom*> classroomsList = _school->getClassroomsList();
	for (std::vector<Classroom*>::iterator it = classroomsList.begin(); it != classroomsList.end(); ++it) {
		if ((*it)->getCurrentCourse() == NULL && (*it)->isEmpty())
			return *it;
	}
	return NULL;
}

Course*		Headmaster::giveNewCourseForStudent(Student* p_student) {
	std::vector<Course*> coursesList = _school->getCoursesList();
	for (std::vector<Course*>::iterator it = coursesList.begin(); it != coursesList.end(); ++it) {
		if (p_student->isGraduateCourse(*it) == false && (*it)->getMaximumNumberOfStudent() > (*it)->getNumberOfStudent())
			return *it;
	}
	return NULL;
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
	std::vector<Professor*> list;
	for(std::vector<Professor*>::iterator it = list.begin(); it != list.end(); ++it) {
		(*it)->doClass();
		std::cout << std::endl;
	}
}

void	Headmaster::studentDoWork() {
	std::vector<Student*> list;
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
	std::cout << printHeader() << getName() << " *RING RING RING*" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(RingBell);
	}
}

void Headmaster::lunchTime() {
	std::cout << printHeader() << getName() << " *RING RING RING* *MIAM MIAM MIAM*" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(LunchTime);
	}
}

void Headmaster::coursesFinish() {
	std::cout << printHeader() << getName() << " *RING RING RING* *MIAM MIAM MIAM*" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(CoursesFinish);
	}
}

