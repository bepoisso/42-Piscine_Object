#pragma once

#include <string>
#include <iostream>

#include "Forward.hpp"

#include "Node.hpp"
#include "Rail.hpp"
#include "Movement.hpp"

class Train: public AMovement {
private:
	const int			_ID;
	const std::string	_name;

	const Node*			_departureStation;				// non-owning: owning by Simulation
	const Node*			_arrivalStation;				// non-owning: owning by Simulation

	Rail*				_currentRail;
	Node*				_currentNode;

	std::string			_departureTime;
	std::string			_stopTime;
public:
	Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake,
		Node* p_departure, Node* p_arrival, std::string p_depTime, std::string p_stopTime);
	~Train();

	int 			getID() 					const { return _ID; }
	std::string 	getName() 					const { return _name; }
	double			getCurrentSpeedLimit()		const;
	const Node*		getDepartureStation()		const { return _departureStation; }
	const Node*		getArrivalStation()			const { return _arrivalStation; }
	std::string		getDepartureTime()			const { return _departureTime; }
	std::string		getStopTime()				const { return _stopTime; }
};
