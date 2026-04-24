#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "observer.hpp"
#include "School.hpp"
#include "Canteen.hpp"
#include "Courtyard.hpp"

class Headmaster : public Staff
{
private:
	Secretary* 			 _secretary;
	std::vector<Form*> _formToValidate; // owning: forms created by Secretary are destroyed by Headmaster
	std::vector<IObserver*> _bellObservers;
	School*					_school;

	bool hasReceivedForm(Form* p_form) const;
	void releaseForm(Form* p_form);
	
public:
	Headmaster(std::string p_name, Secretary *newSecretary);
	~Headmaster();

	std::string 				printHeader() { return "[Headmaster] "; }
	Form*						requestForm(FormType p_formType);
	void						receiveForm(Form* p_form);
	void						submitForm(Form* p_form);
	void						signForm(Form* p_form);
	void						executeForm(Form* p_form);

	Classroom*					giveClassroomToProfessor();
	Classroom*					getClassroom() { return _school->getClassroom(); }
	Canteen*					getCanteen() { return _school->getCanteen(); }
	Courtyard*					getCourtyard() { return _school->getCourtyard(); }
	StaffRestRoom*				getStaffRestRoom() { return _school->getStaffRestRoom(); }

	bool						checkIfCourseExist(std::string p_name);
	Course*						giveNewCourseForStudent(Student* p_student);
	const std::vector<Course*>	getCourseList() { return _school->getCoursesList(); }
	Course*						getCourse(std::string p_name) { return _school->getCourse(p_name); }

	void						professorDoWork();
	void						studentDoWork();

	void						subscribeBell(IObserver* obs);
	void						unsubscribeBell(IObserver	* obs);
	void						ringBell();
	void						lunchTime();
	void						coursesFinish();
};
