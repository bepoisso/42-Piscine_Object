#pragma once

class Worker;

class Tool {
private:
	// Attributes

public:
	// Canonical Form
	Tool() {}
	virtual ~Tool() {}

/* Operator */

/* Getter / Setter */
	virtual void setOwner(Worker *newWorker) = 0;
	virtual Worker *getOwner() = 0;

/* Methode */
	virtual void use() = 0;

};
