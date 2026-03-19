#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"

Worker::Worker(std::string newName) : name(newName) {
	std::cout << "Worker constructor called" << std::endl;
}

Worker::~Worker() {
	removeTools();
	std::cout << "Worker destructor called" << std::endl;
}

void Worker::giveTool(Tool *newTool) {
	if (newTool == NULL) {
		std::cout << name << ": Invalid tool" << std::endl;
		return;
	}

	Worker *previousOwner = newTool->getOwner();
	if (previousOwner != NULL && previousOwner != this) {
		std::cout << name << ": Remove tool from previous owner" << std::endl;
		previousOwner->removeTool(newTool);
	}

	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it) {
		if (*it == newTool) {
			std::cout << name << ": Tool already owned" << std::endl;
			return;
		}
	}

	tools.push_back(newTool);
	newTool->setOwner(this);
	std::cout << name << ": Tool was given" << std::endl;
}

void Worker::removeTool(Tool *tool) {
	if (tool == NULL) {
		std::cout << name << ": Invalid tool" << std::endl;
		return;
	}

	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it) {
		if (*it == tool) {
			tool->setOwner(NULL);
			tools.erase(it);
			std::cout << name << ": Tool was removed" << std::endl;
			return;
		}
	}

	std::cout << name << ": Worker doesn't own this tool" << std::endl;
}

void Worker::removeTools() {
	while (!tools.empty()) {
		Tool *tool = tools.back();
		tool->setOwner(NULL);
		tools.pop_back();
	}
	std::cout << name << ": All tools returned" << std::endl;
}

void Worker::takeTool(Tool *tool) {
	if (tool == NULL) {
		std::cout << name << ": Invalid tool" << std::endl;
		return;
	}

	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it) {
		if (*it == tool) {
			std::cout << name << ": Worker use a tool" << std::endl;
			tool->use();
			return;
		}
	}

	std::cout << name << ": Worker doesn't own this tool" << std::endl;
}

void Worker::takeTools() {
	if (tools.empty()) {
		std::cout << name << ": Worker doesn't own any tool" << std::endl;
		return;
	}

	std::cout << name << ": Worker use all tools" << std::endl;
	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
		(*it)->use();
}

