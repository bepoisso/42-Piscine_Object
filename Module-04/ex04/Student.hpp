#pragma once

#include <vector>
#include <map>

#include "Foward.hpp"
#include "Person.hpp"
#include "observer.hpp"

class Student : public Person, public IObserver
{
private:
	std::vector<Course*> _subscribedCourse;
	std::map<Course*, int> _scoreCourse;
	std::vector<Course*> _graduateCourse;
	Headmaster* _headmasterMediator;

public:
	Student(std::string p_name);
	void setHeadmasterMediator(Headmaster* headmaster);
	Headmaster* getheadmasterMediator() { return _headmasterMediator; }
	std::string printHeader() { return "[Student] "; }
	int getCurrentScore(Course* p_course) { return _scoreCourse[p_course]; }
	void attendClass();
	void exitClass();
	void graduate(Course* p_course);
	void receiveLesson(Course* p_course);
	void addSubscribedCourse(Course* p_course) { _subscribedCourse.push_back(p_course); }
	void addGraduateCourse(Course* p_course) { _graduateCourse.push_back(p_course); }
	bool isGraduateCourse(Course* p_course);
	bool isSubscribedCourse(Course* p_course);
	void onBell(Event event);

};
