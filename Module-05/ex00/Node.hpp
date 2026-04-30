#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Forward.hpp"


class Node{
private:
	const std::string _name;

	std::vector<Rail*> _railsConnection;			// non-owning: Rail are owned bt Simulation

public:
	Node(std::string p_name);
	~Node();

	const std::string getName() const { return _name; }
	std::vector<Rail*> getRails() { return _railsConnection; }
	void addRail(Rail* p_rail);
	void removeRail(Rail* p_rail);

	//TODO: (debug) Supprimer avant mis en prod
	void D_printConnection();
};
