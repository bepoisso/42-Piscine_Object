#pragma once

#include <string>

class IMobilizable {
public:
	virtual ~IMobilizable() {}
	virtual void mobilizeHours(int hours) = 0;
	virtual int getMobilizedHoursLeft() const = 0;
};

class IAbsenceTrackable {
public:
	virtual ~IAbsenceTrackable() {}
	virtual void declareAbsenceHours(int hours) = 0;
	virtual int getAbsenceHoursLeft() const = 0;
};

class ISchoolTrackable {
public:
	virtual ~ISchoolTrackable() {}
	virtual void declareSchoolHours(int hours) = 0;
	virtual int getSchoolhoursLeft() const = 0;
};

class Employee {
private:
	std::string name;
	int hourlyValue;

public:
	Employee(std::string newName, int newHourlyValue) : name(newName), hourlyValue(newHourlyValue) {}
	virtual ~Employee() {}

	const std::string getName() const;
	int getHourlyValue() const;

	virtual int executeWorkday() = 0;
	virtual int calculateMonthlyPay() const = 0;

};

const std::string Employee::getName() const {
	return name;
}

int Employee::getHourlyValue() const {
	return hourlyValue;
}
