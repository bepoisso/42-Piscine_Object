#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

#include "Classroom.hpp"
#include "Course.hpp"
#include "CourseFinishedForm.hpp"
#include "Headmaster.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "Professor.hpp"
#include "Secretary.hpp"
#include "Student.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "Room.hpp"
#include "SecretarialOffice.hpp"
#include "StaffRestRoom.hpp"
#include "HeadmasterOffice.hpp"
#include "Courtyard.hpp"
#include "Canteen.hpp"


class School {
private:
	Headmaster 	_headmaster;
	Secretary 	_secretary;

	std::vector<Student> 	_studentsList;
	std::vector<Professor>	_professorsList;

	std::vector<Course*>	_coursesList;
	std::vector<Classroom*> _classroomList;

	Canteen _canteen;
	SecretarialOffice _secretariaOffice;
	HeadmasterOffice _headmasterOffice;
	StaffRestRoom _staffRoom;
	Courtyard _courtyard;

	int _day;

public:
	School();
	~School();

	void runDayRoutine(); 
	void recruteStudent();
	void recruteProfessor();
	void launchClasses();
	void requestRingBell();
	Course* getCourse(std::string p_name);
	std::vector<Student*> getStudents();
	std::vector<Professor*> getProfessors();
	Headmaster getHeadmaster() { return _headmaster; }
	Secretary getSecretary() { return _secretary; }
	void graduationCeremony();

	void startLunch();

	void printDay();
	const SecretarialOffice getSecretariaOffice();
	const HeadmasterOffice getHeadmasterOffice();
	const StaffRestRoom getStaffRestRoom();
	const Courtyard getCourtyard();
	void initProfessors();
	void initStudents();
	void addCourse(Course* p_course) { _coursesList.push_back(p_course); }
	void addClassroom(Classroom* p_classroom) { _classroomList.push_back(p_classroom); }
	bool nameExist(std::string p_name);
};
