#include "Headmaster.hpp"
#include "Form.hpp"
#include "Secretary.hpp"

#include <iostream>

Headmaster::~Headmaster() {
	for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
		delete *it;
	_formToValidate.clear();
	for (std::vector<Course*>::iterator it = _courseList.begin(); it != _courseList.end(); ++it)
		delete *it;
	_courseList.clear();
	for (std::vector<Classroom*>::iterator it = _classroomList.begin(); it != _classroomList.end(); ++it)
		delete *it;
	_classroomList.clear();
}

Headmaster::Headmaster(std::string p_name, Secretary* newSecretary) : Staff(p_name), _secretary(newSecretary) {
}

Form* Headmaster::requestForm(FormType p_formType) {
	if (!_secretary) {
		std::cout << "[Headmaster] cannot request form: no secretary assigned" << std::endl;
		return NULL;
	}
	Form* form = _secretary->createForm(p_formType);
	if (!form) {
		std::cout << "[Headmaster] failed to request form" << std::endl;
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
	if (!hasReceivedForm(p_form))
		receiveForm(p_form);
	signForm(p_form);
	if (p_form->getIsSigned())
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
		std::cout << "[Headmaster] refused to sign: form was not received" << std::endl;
		return;
	}
	if (!p_form->isComplete()) {
		std::cout << "[Headmaster] refused to sign: mandatory form data is missing" << std::endl;
		return;
	}
	std::cout << "[Headmaster] signed form " << p_form->getFormName() << std::endl;
	p_form->setIsSigned(true);
}

void	Headmaster::executeForm(Form* p_form) {
	if (!hasReceivedForm(p_form)) {
		std::cout << "[Headmaster] refused to execute: form was not received" << std::endl;
		return;
	}
	std::cout << "[Headmaster] execute form " << p_form->getFormName() << std::endl;
	p_form->execute();
	releaseForm(p_form);
}

void	Headmaster::receiveCourse(Course* p_course) {
	if (!p_course) {
		std::cout << "[Headmaster] cannot save this course. Course empty" << std::endl;
		return ;
	}
	_courseList.push_back(p_course);
}

long long	Headmaster::getNextIndexClassroom() {
	if (_classroomList.empty())
		return 0;
	return _classroomList.back()->getID() + 1;
}

Classroom*	Headmaster::giveClassroomToProfessor() {
	for (std::vector<Classroom*>::iterator it = _classroomList.begin(); it != _classroomList.end(); ++it) {
		if ((*it)->getCurrentCourse() == NULL)
			return *it;
	}
	return NULL;
}

Course*		Headmaster::giveNewCourseForStudent(Student* p_student) {
	for (std::vector<Course*>::iterator it = _courseList.begin(); it != _courseList.end(); ++it) {
		if (p_student->isGraduateCourse(*it) == false && (*it)->getMaximumNumberOfStudent() > (*it)->getNumberOfStudent())
			return *it;
	}
	return NULL;
}

bool		Headmaster::checkisCourseExist(std::string p_name) {
	for (std::vector<Course*>::iterator it = _courseList.begin(); it != _courseList.end(); ++it) {
		if (p_name == (*it)->getName())
			return true;
	}
	return false;
}

void Headmaster::ringBell() {
	std::cout << "[Headmaster] *RING RING RING*" << std::endl;
	for(std::vector<IObserver*>::iterator it = _bellObservers.begin(); it != _bellObservers.end(); ++it) {
		if (*it)
			(*it)->onBell(RingBell);
	}
}
