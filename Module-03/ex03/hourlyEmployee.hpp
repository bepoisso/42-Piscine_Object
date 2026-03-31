#pragma once

#include "employee.hpp"

class TempWorker : public Employee, public IMobilizable {
private:
	int mobilizedHoursLeft;
	int workedHoursMonth;

public:
	TempWorker(std::string name, int hourlyValue) : Employee(name, hourlyValue), mobilizedHoursLeft(7 * 20), workedHoursMonth(0) {}
	~TempWorker() {}

	void mobilizeHours(int hours) override;
	int getMobilizedHoursLeft() const override;

	int executeWorkday() override;
	int calculateMonthlyPay() const override;

};

void TempWorker::mobilizeHours(int hours) {
	if (hours <= 0)
		return;
	mobilizedHoursLeft += hours;
}

int TempWorker::getMobilizedHoursLeft() const {
	return mobilizedHoursLeft;
}

int TempWorker::executeWorkday() {
	if (mobilizedHoursLeft <= 0)
		return 0;

	int workedToday = 7;
	if (mobilizedHoursLeft < 7)
		workedToday = mobilizedHoursLeft;

	mobilizedHoursLeft -= workedToday;
	workedHoursMonth += workedToday;
	return workedToday;
}

int TempWorker::calculateMonthlyPay() const {
	return workedHoursMonth * getHourlyValue();
}
