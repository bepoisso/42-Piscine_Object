#pragma once

#include <string>
#include <vector>

#include "Struct.hpp"

class Tool;
class Workshop;


class Worker
{
private:
	std::string name;
	Position pos;
	Statistic stat;
	std::vector<Tool *> tools;
	std::vector<Workshop *> workshops;

public:
	Worker(std::string newName);
	~Worker();

	void giveTool(Tool *newTool);
	void removeTool(Tool *tool);
	void removeTools();
	void takeTool(Tool *tool);
	void takeTools();

	void addWorkshop(Workshop *workshop);
	void removeWorkshop(Workshop *workshop);
	void work(Workshop *workshop);
};
