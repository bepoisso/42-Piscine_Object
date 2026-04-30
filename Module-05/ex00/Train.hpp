#pragma once

#include <string>
#include <iostream>

#include "Forward.hpp"

#include "Node.hpp"

class Train {
private:
	const int			_ID;
	const std::string	_name;
	const int			_weight;
	const float			_frictionCoefficient;
	const float			_accelerationMax;
	const float			_brakeMax;

	const Node*			_departureStation;				// non-owning: owning by Simulation
	const Node*			_arrivalStation;				// non-owning: owning by Simulation

	//? Es ce que on fait une Aclass Position pour les Node et les Rail ? Ce qui permetrais d'avoir
	//? Position	_currentPosition

	std::string			_departureTime;
	std::string			_stopTime;
public:
	Train(std::string p_name, int p_weight, float p_friction, float p_acceleration, float p_brake,
		Node* p_departure, Node* p_arrival, std::string p_depTime, std::string p_stopTime);
	~Train();

	int 			getID() 					const { return _ID; }
	std::string 	getName() 					const { return _name; }
	int 			getWeight() 				const { return _weight; }
	float			getFrictionCoefficient()	const { return _frictionCoefficient; }
	float			getAccelerationMax() 		const { return _accelerationMax; }
	float			getBrakeMax() 				const { return _brakeMax; }
	const Node*		getDepartureStation() 		const { return _departureStation; }
	const Node*		getArrivalStation() 		const { return _arrivalStation; }
	std::string		getDepartureTime() 			const { return _departureTime; }
	std::string		getStopTime() 				const { return _stopTime; }
};
