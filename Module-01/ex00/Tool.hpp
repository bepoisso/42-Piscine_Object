#pragma once

class Worker;

class Tool {
private:
	// Attributes

public:
	// Canonical Form
	Tool() {}
	virtual ~Tool() {}
	Tool(const Tool &other) {
		(void)other;
	}
	Tool &operator=(const Tool &other) {
		(void)other;
		return (*this);
	}

/* Operator */

/* Getter / Setter */
	virtual void setOwner(Worker *newWorker) = 0;
	virtual Worker *getOwner() = 0;

/* Methode */
	virtual void use() = 0;

};
