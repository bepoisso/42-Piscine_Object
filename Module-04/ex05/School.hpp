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
	Secretary	_secretary;
	Headmaster	_headmaster;

	Canteen 			_canteen;
	SecretarialOffice	_secretariaOffice;
	HeadmasterOffice	_headmasterOffice;
	StaffRestRoom		_staffRoom;
	Courtyard			_courtyard;
	
	int _day;

	std::vector<Student*>	_studentsList;			// owning: School owns these Student instances
	std::vector<Professor*>	_professorsList;		// owning: School owns these Professor instances

	std::vector<Course*>	_coursesList;			// owning: School owns these Course instances
	std::vector<Classroom*>	_classroomList;			// owning: School owns these Classroom instances



public:
	School();
	~School();

	void runDayRoutine(); 
	void recruteStudent();
	void recruteProfessor();

	void launchClasses();
	void requestRingBell() { _headmaster.ringBell(); }
	void requestLunchTime() { _headmaster.lunchTime(); }
	void requestCourseFinish() { _headmaster.coursesFinish(); }
	Course* getCourse(std::string p_name);
	Classroom* getClassroom();
	std::vector<Student*> getStudents() { return _studentsList; }
	std::vector<Professor*> getProfessors() { return _professorsList; }
	Headmaster getHeadmaster() { return _headmaster; }
	Secretary getSecretary() { return _secretary; }
	void graduationCeremony();

	void printDay();
	std::string printHeader() { return "[SCHOOL] "; }
	StaffRestRoom* getStaffRestRoom() { return &_staffRoom; }
	Courtyard* getCourtyard() { return &_courtyard;}
	Canteen* getCanteen() { return &_canteen; }
	void initProfessors();
	void initStudents();
	void initSecretary();
	void initHeadmaster();
	bool nameExist(std::string p_name);
	bool isAllWorkDone();
	const std::vector<Course*> getCoursesList() { return _coursesList; }
	const std::vector<Classroom*> getClassroomsList() { return _classroomList; }
};
