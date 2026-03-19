#pragma once

#include <string>
#include <vector>

#include "Struct.hpp"

class Tool;


class Worker
{
private:
	std::string name;
	Position pos;
	Statistic stat;
	std::vector<Tool *> tools;

public:
	Worker(std::string newName);
	~Worker();

	void giveTool(Tool *newTool);
	void removeTool(Tool *tool);
	void removeTools();
	void takeTool(Tool *tool);
	void takeTools();
};
