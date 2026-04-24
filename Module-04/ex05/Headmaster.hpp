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
#include "Canteen.hpp"
#include "Courtyard.hpp"

class Headmaster : public Staff
{
private:
	School*					_school;					// non-owning: owning by School
	Secretary*				_secretary;					// non-owning: owning by School
	std::vector<Form*> 		_formToValidate;			// owning: Headmaster owns these Form instances until transferred to the SecretariaOffice by Secretary
	std::vector<IObserver*> _bellObservers;				// Non-owning: observers are created by Student and Professor (polymorphism); do not delete them here

	bool hasReceivedForm(Form* p_form) const;
	void releaseForm(Form* p_form);
	
public:
	Headmaster(std::string p_name, Secretary *newSecretary);
	~Headmaster();

	void						setSchool(School* p_school) { _school = p_school; }

	std::string 				printHeader() { return "\033[38;5;208m[Headmaster]\033[0m "; }
	Form*						requestForm(FormType p_formType);
	void						receiveForm(Form* p_form);
	void						submitForm(Form* p_form);
	void						signForm(Form* p_form);
	void						executeForm(Form* p_form);

	Classroom*					giveClassroomToProfessor();
	Classroom*					getClassroom();
	Canteen*					getCanteen();
	Courtyard*					getCourtyard();
	StaffRestRoom*				getStaffRestRoom();

	bool						checkIfCourseExist(std::string p_name);
	Course*						giveNewCourseForStudent(Student* p_student);
	const std::vector<Course*>	getCourseList();
	Course*						getCourse(std::string p_name);

	void						professorDoWork();
	void						studentDoWork();

	void						subscribeBell(IObserver* obs);
	void						unsubscribeBell(IObserver	* obs);
	void						ringBell();
	void						lunchTime();
	void						coursesFinish();
};
