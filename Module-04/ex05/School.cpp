#include "School.hpp"

School::School() : _secretary("Rubeus Hagrid"), _headmaster("Albus Dumbledore", &_secretary), _canteen(), _secretaryOffice(), _headmasterOffice, _staffRoom, _courtyard(), _day(0) {
	_secretary.setHeadmasterMediator(&_headmaster);
	
	std::cout << "\n--- Creating professors ---" << std::endl;
	_professorsList.push_back(Professor("Minerva McGonagall"));
	_professorsList.push_back(Professor("Severus Snape"));
	_professorsList.push_back(Professor("Horace Slughorn"));
	_professorsList.push_back(Professor("Filius Flitwick"));
	_professorsList.push_back(Professor("Pomona Sprout"));
	_professorsList.push_back(Professor("Alastor Moody"));
	initProfessors();
	
	std::cout << "\n--- Creating students ---" << std::endl;
	_studentsList.push_back(Student("Harry Potter"));
	_studentsList.push_back(Student("Hermion Granger"));
	_studentsList.push_back(Student("Ron Wisley"));
	_studentsList.push_back(Student("Neville Longbottom"));
	_studentsList.push_back(Student("Luna Lovegood"));
	_studentsList.push_back(Student("Draco Malfoy"));
	_studentsList.push_back(Student("Ginny Weasley"));
	_studentsList.push_back(Student("Cedric Diggory"));
	_studentsList.push_back(Student("Cho Chang"));
	_studentsList.push_back(Student("Lavender Brown"));
	_studentsList.push_back(Student("Parvati Patil"));
	_studentsList.push_back(Student("Fred Weasley"));
	_studentsList.push_back(Student("George Weasley"));
	_studentsList.push_back(Student("Seamus Finnigan"));
	_studentsList.push_back(Student("Dean Thomas"));
	_studentsList.push_back(Student("Padma Patil"));
	_studentsList.push_back(Student("Michael Corner"));
	_studentsList.push_back(Student("Terry Boot"));
	_studentsList.push_back(Student("Hannah Abbott"));
	_studentsList.push_back(Student("Justin Finch-Fletchley"));
	initStudents();
}

School::~School() {
}

void School::runDayRoutine() {
	printDay();
	// 1. launch classes
	launchClasses();
	// 2. allow student and professor to go on recreation
	requestRingBell();
	requestRingBell();
	// 3. launch classes
	launchClasses();
	// 4. launch lunch
	startLunch();
	// 5. launch classes
	launchClasses();
	// 6. allow student and professor to go on recreation
	requestRingBell();
	requestRingBell();
	// 7. launch classes
	launchClasses();
	_day++;
}

//* Recruter des student et les ajouter a la liste
//? Comment leurs donner un nom
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
	_studentsList.push_back(Student(result));
}

//* Recruter des professor et les ajouter a la liste
//? Comment leurs donner un nom
void School::recruteProfessor() {
	std::string name[] = {
	"Gilderoy Lockhart", "Remus Lupin", "Sybill Trelawney",
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
	_professorsList.push_back(Professor(result));
}

//* Les profs et les eleves travail
void School::launchClasses() {

}

//* Make the headmaster ring the bel
void School::requestRingBell() {
	_headmaster.ringBell();
}

//* return a course with a given name
Course* School::getCourse(std::string p_name) {
	Course target(p_name);
	for (std::vector<Course*>::iterator it = _coursesList.begin(); it != _coursesList.end(); ++it) {
		if ((*it)->getName() == p_name)
			return *it;
	}
	
	_coursesList.push_back(&target);
	return _coursesList.back();
}

//* return a vector containing every student in school
std::vector<Student*> School::getStudents() {
	std::vector<Student*> result;
	for (std::vector<Student>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		result.push_back(&(*it));
	}
	return result;
}

//* return a vector containing every professor in school
std::vector<Professor*> School::getProfessors() {
	std::vector<Professor*> result;
	for (std::vector<Professor>::iterator it = _professorsList.begin(); it != _professorsList.end(); ++it) {
		result.push_back(&(*it));
	}
	return result;
}

//* launch the graduation of every student that can graduate at a desired moment
void School::graduationCeremony() {
	std::cout << "==== GRADUATION CEREMONY ===" << std::endl;
	for (std::vector<Student>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		bool flag = true;
		for (std::vector<Course*>::iterator jt = _coursesList.begin(); jt != _coursesList.end(); ++it) {
			if (!it->isGraduateCourse(*jt))
				flag = false;
		}
		if (flag) {
			std::cout << "[CEREMONY] Congratulation " << it->getName() << " you are now graduate form Hogward!" << std::endl;
			it = _studentsList.erase(it);
		}
	}
}

//* demande au professors et au students d'allez manger
void School::startLunch() {
	//TODO: cree les fonction go lunch pour tous les person
}


void School::printDay() {
	std::cout << "====================" << std::endl;
	std::cout << "        DAY: " << _day << std::endl;
	std::cout << "====================" << std::endl;
}

const SecretarialOffice School::getSecretariaOffice() {
	return _secretariaOffice;
}

const HeadmasterOffice School::getHeadmasterOffice() {
	return _headmasterOffice;
}

const StaffRestRoom School::getStaffRestRoom() {
	return _staffRoom;
}

const Courtyard School::getCourtyard() {
	return _courtyard;
}

void School::initProfessors() {
	for (std::vector<Professor>::iterator it = _professorsList.begin(); it != _professorsList.end(); ++it) {
		(*it).setHeadmasterMediator(&_headmaster);
		std::cout << (*it).printHeader() << (*it).getName() << " just arrived to the Hogward!" << std::endl;
	}
}

void School::initStudents() {
	for (std::vector<Student>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		(*it).setHeadmasterMediator(&_headmaster);
		std::cout << (*it).printHeader() << (*it).getName() << " just arrived to Hogward!" << std::endl;
	}
}

bool School::nameExist(std::string p_name) {
	for (std::vector<Student>::iterator it = _studentsList.begin(); it != _studentsList.end(); ++it) {
		if (it->getName() == p_name)
			return true;
	}
	for (std::vector<Professor>::iterator it = _professorsList.begin(); it != _professorsList.end(); ++it) {
		if (it->getName() == p_name)
			return true;
	}
	return false;
}

//TODO: Faire en sorte que SecretariaOffice own les Forms
//TODO: Faire en sorte que le headmaster donne toutes les choses qu'il n'own plus a School
