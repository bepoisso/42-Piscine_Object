#pragma once

#include <vector>
#include <iostream>
#include "employee.hpp"

class EmployeeManagement {
private:
	std::vector<Employee*> employees;

public:
	EmployeeManagement() {}
	~EmployeeManagement() {}

	void addEmployee(Employee* employee);
	void removeEmployee(Employee* employee);
	void executeWorkday();
	void calculatePayroll();

};

void EmployeeManagement::addEmployee(Employee *employee) {
	if (employee == NULL)
		return;
	employees.push_back(employee);
}

void EmployeeManagement::removeEmployee(Employee* employee) {
	if (employee == NULL)
		return;
	for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
		if (*it == employee) {
			employees.erase(it);
			return;
		}
	}
}

void EmployeeManagement::executeWorkday() {
	for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
		(*it)->executeWorkday();
	}
}

void EmployeeManagement::calculatePayroll() {
	for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
		std::cout << "For " << (*it)->getName() << " : " << (*it)->calculateMonthlyPay() << std::endl;
	}
}
