#pragma once

#include <string>
#include <vector>

#include "Foward.hpp"
#include "Staff.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "Course.hpp"

class Headmaster : public Staff
{
private:
	Secretary* 			 _secretary;
	std::vector<Form*> _formToValidate; // owning: forms created by Secretary are destroyed by Headmaster
	std::vector<Course*> _courseList; // owning: course created by Professor are destroyed by Headmaster
	bool hasReceivedForm(Form* p_form) const;
	void releaseForm(Form* p_form);
	
public:
	Headmaster(std::string p_name, Secretary *newSecretary);
	~Headmaster();

	Form*	requestForm(FormType p_formType);
	void	receiveForm(Form* p_form);
	void	submitForm(Form* p_form);
	void	signForm(Form* p_form);
	void	executeForm(Form* p_form);

	void	receiveCourse(Course* p_course);


};
