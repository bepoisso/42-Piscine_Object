#include "School.hpp"

School::School() : _secretary("Rubeus Hagrid"), _headmaster("Albus Dumbledore", &_secretary), _canteen(), _secretariaOffice(), _headmasterOffice(), _staffRoom(), _courtyard(), _day(1) {
	std::cout << "\n--- Creating Headmaster & Secretary ---" << std::endl;
	initHeadmaster();
	initSecretary();

	std::cout << "\n--- Creating Classrooms ---" << std::endl;
	_classroomList.push_back(new Classroom());
	_classroomList.push_back(new Classroom());
	_classroomList.push_back(new Classroom());
	_classroomList.push_back(new Classroom());
	_classroomList.push_back(new Classroom());
	
	std::cout << "\n--- Creating professors ---" << std::endl;
	_professorsList.push_back(new Professor("Minerva McGonagall"));
	_professorsList.push_back(new Professor("Severus Snape"));
	_professorsList.push_back(new Professor("Horace Slughorn"));
	_professorsList.push_back(new Professor("Filius Flitwick"));
	_professorsList.push_back(new Professor("Pomona Sprout"));
	_professorsList.push_back(new Professor("Gilderoy Lockhart"));
	initProfessors();
	
	std::cout << "\n--- Creating students ---" << std::endl;
	_studentsList.push_back(new Student("Harry Potter"));
	_studentsList.push_back(new Student("Hermion Granger"));
	_studentsList.push_back(new Student("Ron Wisley"));
	_studentsList.push_back(new Student("Neville Longbottom"));
	_studentsList.push_back(new Student("Luna Lovegood"));
	_studentsList.push_back(new Student("Draco Malfoy"));
	_studentsList.push_back(new Student("Ginny Weasley"));
	_studentsList.push_back(new Student("Cedric Diggory"));
	_studentsList.push_back(new Student("Cho Chang"));
	_studentsList.push_back(new Student("Lavender Brown"));
	_studentsList.push_back(new Student("Parvati Patil"));
	_studentsList.push_back(new Student("Fred Weasley"));
	_studentsList.push_back(new Student("George Weasley"));
	_studentsList.push_back(new Student("Seamus Finnigan"));
	_studentsList.push_back(new Student("Dean Thomas"));
	_studentsList.push_back(new Student("Padma Patil"));
	_studentsList.push_back(new Student("Michael Corner"));
	_studentsList.push_back(new Student("Terry Boot"));
	_studentsList.push_back(new Student("Hannah Abbott"));
	_studentsList.push_back(new Student("Justin Finch-Fletchley"));
	initStudents();
}

School::~School() {
	for (std::vector<Course*>::iterator it = _coursesList.begin(); it != _coursesList.end(); ++it)
		delete *it;
	for (std::vector<Classroom*>::iterator it = _classroomList.begin(); it != _classroomList.end(); ++it)
		delete *it;
	for (std::vector<Professor*>::iterator it = _professorsList.begin(); it != _professorsList.end(); ++it)
		delete *it;
	for (std::vector<Student*>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it)
		delete *it;
	_professorsList.clear();
	_studentsList.clear();
	_coursesList.clear();
	_classroomList.clear();
	
}

/*
	1. launch classes
	2. allow student and professor to go on recreation
	3. launch classes
	4. launch lunch
	5. launch classes
	6. allow student and professor to go on recreation
	7. launch classes
*/

void School::runDayRoutine() {
	printDay();
	launchClasses();
	requestRingBell();
	requestRingBell();
	requestLunchTime();
	requestRingBell();
	requestRingBell();
	requestRingBell();
	requestCourseFinish();

	// if (_day % 10 == 1 && _day > 1)
	// 	graduationCeremony();
	_day++;
}

void School::recruteStudent() {
	std::string name[] = {
	"Alice Abercrombie", "Finwood Zabini", "Blaise Zabini", "Cormac McLaggen",
	"Ernie Macmillan", "Fay Dunbar", "Gregory Goyle", "Hufflepuff Smith",
	"Iris Wildsmith", "Justin Finch-Fletchley", "Kevin Entwhistle", "Leanne",
	"Marcus Flint", "Natasha Bulstrode", "Orion Nott", "Pansy Parkinson",
	"Quirrell Quirke", "Roger Davies", "Sander Bolt", "Terence Boot",
	"Uriah Stump", "Vincent Crabbe", "Walter Vaunt", "Xenophilius Lovegood",
	"Yasmine Yaxley", "Zacharias Smith", "" };
	
	int i = 0;
	std::string result = "";
	while (name[i] != "") {
		if (!nameExist(name[i]))
			result = name[i];
	}
	if (result == "") {
		std::cout << "[SCHOOL] No more students subscribed to Hogward!" << std::endl;
		return;
	}
	_studentsList.push_back(new Student(result));
	_studentsList.back()->setHeadmasterMediator(&_headmaster);
	std::cout << _studentsList.back()->printHeader() << _studentsList.back()->getName() << " just arrived to Hogward!" << std::endl;
}

void School::recruteProfessor() {
	std::string name[] = {
	"Alastor Moody", "Remus Lupin", "Sybill Trelawney",
	"Dolores Umbridge", "Charity Burbage", "Quirinus Quirrell",
	"Cuthbert Binns", "Sulivan Kettleburn", "Garrick Ollivander"};

	int i = 0;
	std::string result = "";
	while (name[i] != "") {
		if (!nameExist(name[i]))
			result = name[i];
	}
	if (result == "") {
		std::cout << "[SCHOOL] No more professors subscribed to Hogward!" << std::endl;
		return;
	}
	_professorsList.push_back(new Professor(result));
	_professorsList.back()->setHeadmasterMediator(&_headmaster);
	std::cout << _professorsList.back()->printHeader() << _professorsList.back()->getName() << " just arrived to Hogward!" << std::endl;
}

void School::launchClasses() {
	std::cout << "---  Headmaster ask professors & students to work ---" << std::endl;
	_headmaster.studentDoWork();
	_headmaster.professorDoWork();
}

Course* School::getCourse(std::string p_name) {
	Course* target = new Course(p_name);
	for (std::vector<Course*>::iterator it = _coursesList.begin(); it != _coursesList.end(); ++it) {
		if ((*it)->getName() == p_name)
			return *it;
	}
	
	_coursesList.push_back(target);
	return _coursesList.back();
}

Classroom* School::getClassroom() {
	_classroomList.push_back(new Classroom());
	return _classroomList.back();
}

void School::graduationCeremony() {
	std::cout << "--- GRADUATION CEREMONY ---" << std::endl;
	for (std::vector<Student*>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		bool flag = true;
		for (std::vector<Course*>::iterator jt = _coursesList.begin(); jt != _coursesList.end(); ++it) {
			if (!(*it)->isGraduateCourse(*jt))
				flag = false;
		}
		if (flag) {
			std::cout << "[CEREMONY] Congratulation " << (*it)->getName() << " you are now graduate from Hogward!" << std::endl;
			_studentsList.erase(it);
		}
	}
}

void School::printDay() {
	std::cout << "\n\n====================" << std::endl;
	std::cout << "        DAY: " << _day << std::endl;
	std::cout << "====================" << std::endl;
}

void School::initProfessors() {
	for (std::vector<Professor*>::iterator it = _professorsList.begin(); it != _professorsList.end(); ++it) {
		(*it)->setHeadmasterMediator(&_headmaster);
		std::cout << (*it)->printHeader() << (*it)->getName() << " just arrived to the Hogward!" << std::endl;
		(*it)->initCourse();
	}
}

void School::initStudents() {
	for (std::vector<Student*>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		(*it)->setHeadmasterMediator(&_headmaster);
		std::cout << (*it)->printHeader() << (*it)->getName() << " just arrived to Hogward!" << std::endl;
	}
}

void School::initSecretary() {
	_secretary.setHeadmasterMediator(&_headmaster);
	std::cout << _secretary.printHeader() << _secretary.getName() << " just arrived to Hogward!" << std::endl;
	_secretariaOffice.enter(&_secretary);
}

void School::initHeadmaster() {
	_headmaster.setSchool(this);
	std::cout << _headmaster.printHeader() << _headmaster.getName() << " just arrived to Hogward!" << std::endl;
	_headmasterOffice.enter(&_headmaster);
}

bool School::nameExist(std::string p_name) {
	for (std::vector<Student*>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		if ((*it)->getName() == p_name)
			return true;
	}
	for (std::vector<Professor*>::iterator it = _professorsList.begin(); it != _professorsList.end(); ++it) {
		if ((*it)->getName() == p_name)
			return true;
	}
	return false;
}

bool School::isAllWorkDone() {
	std::vector<Student*>::iterator it = _studentsList.begin();
	if (it == _studentsList.end())
		return true;
	return false;
}
