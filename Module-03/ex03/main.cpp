#include <iostream>
#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main() {
	EmployeeManagement manager;

	TempWorker* temp = new TempWorker("Tom", 20);
	ContractEmployee* contract = new ContractEmployee("Claire", 30);
	Apprentice* apprentice = new Apprentice("Leo", 18);

	manager.addEmployee(temp);
	manager.addEmployee(contract);
	manager.addEmployee(apprentice);

	// Preparation of special schedules
	temp->mobilizeHours(40);
	contract->declareAbsenceHours(14);
	apprentice->declareAbsenceHours(7);
	apprentice->declareSchoolHours(28);

	// Simulate one complete month (20 workdays)
	for (int day = 0; day < 20; ++day) {
		manager.executeWorkday();
	}

	std::cout << "=== Payroll over last month ===" << std::endl;
	manager.calculatePayroll();

	delete temp;
	delete contract;
	delete apprentice;

	return 0;
}
