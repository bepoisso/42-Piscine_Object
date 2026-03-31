#pragma once

#include "employee.hpp"


class ContractEmployee : public Employee, public IAbsenceTrackable {
private:
	int absenceHoursLeft;
	int workedHoursMonth;

public:
	ContractEmployee(std::string name, int hourlyValue) : Employee(name, hourlyValue), absenceHoursLeft(0), workedHoursMonth(0) {}
	~ContractEmployee() {}

	void declareAbsenceHours(int hours) override;
	int getAbsenceHoursLeft() const override;

	int executeWorkday() override;
	int calculateMonthlyPay() const override;
};

class Apprentice : public Employee, public IAbsenceTrackable, public ISchoolTrackable{
private:
	int absenceHoursLeft;
	int schoolHoursLeft;
	int workedHoursMonth;
	int schoolHoursMonth;

public:
	Apprentice(std::string name, int hourlyValue);
	~Apprentice();

	void declareAbsenceHours(int hours) override;
	int getAbsenceHoursLeft() const override;

	void declareSchoolHours(int hours) override;
	int getSchoolhoursLeft() const override;

	int executeWorkday() override;
	int calculateMonthlyPay() const override;
};

void ContractEmployee::declareAbsenceHours(int hours) {
	if (hours <= 0)
		return;
	absenceHoursLeft += hours;
}

int ContractEmployee::getAbsenceHoursLeft() const {
	return absenceHoursLeft;
}

int ContractEmployee::executeWorkday() {
	int absentToday = 0;
	if (absenceHoursLeft > 0) {
		absentToday = (absenceHoursLeft < 7) ? absenceHoursLeft : 7;
		absenceHoursLeft -= absentToday;
	}

	int workedToday = 7 - absentToday;
	workedHoursMonth += workedToday;
	return workedToday;
}

int ContractEmployee::calculateMonthlyPay() const {
	return workedHoursMonth * getHourlyValue();
}

Apprentice::Apprentice(std::string name, int hourlyValue)
	: Employee(name, hourlyValue), absenceHoursLeft(0), schoolHoursLeft(0), workedHoursMonth(0), schoolHoursMonth(0) {}

Apprentice::~Apprentice() {}

void Apprentice::declareAbsenceHours(int hours) {
	if (hours <= 0)
		return;
	absenceHoursLeft += hours;
}

int Apprentice::getAbsenceHoursLeft() const {
	return absenceHoursLeft;
}

void Apprentice::declareSchoolHours(int hours) {
	if (hours <= 0)
		return;
	schoolHoursLeft += hours;
}

int Apprentice::getSchoolhoursLeft() const {
	return schoolHoursLeft;
}

int Apprentice::executeWorkday() {
	int remaining = 7;

	if (absenceHoursLeft > 0) {
		int absentToday = (absenceHoursLeft < remaining) ? absenceHoursLeft : remaining;
		absenceHoursLeft -= absentToday;
		remaining -= absentToday;
	}

	if (schoolHoursLeft > 0 && remaining > 0) {
		int schoolToday = (schoolHoursLeft < remaining) ? schoolHoursLeft : remaining;
		schoolHoursLeft -= schoolToday;
		schoolHoursMonth += schoolToday;
		remaining -= schoolToday;
	}

	workedHoursMonth += remaining;
	return remaining;
}

int Apprentice::calculateMonthlyPay() const {
	return (workedHoursMonth * getHourlyValue()) + ((schoolHoursMonth * getHourlyValue()) / 2);
}
