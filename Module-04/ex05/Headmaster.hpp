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

class Headmaster : public Staff
{
private:
	Secretary* 			 _secretary;
	std::vector<Form*> _formToValidate; // owning: forms created by Secretary are destroyed by Headmaster
	std::vector<Course*> _courseList; // owning: course created by Professor are destroyed by Headmaster
	std::vector<Classroom*> _classroomList; // owning: clasroom created by form are destroyed by Headmaster
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

	void						receiveCourse(Course* p_course);
	void						addClassroomList(Classroom* p_classroom) { _classroomList.push_back(p_classroom); }
	long long					getNextIndexClassroom();
	bool						checkIfCourseExist(std::string p_name);
	Classroom*					giveClassroomToProfessor();
	Course*						giveNewCourseForStudent(Student* p_student);
	const std::vector<Course*>	getCourseList() { return _courseList; }

	void						subscribeBell(IObserver* obs);
	void						unsubscribeBell(IObserver	* obs);
	void						ringBell();
};
