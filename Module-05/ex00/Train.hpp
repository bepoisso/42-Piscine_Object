#pragma once

#include <string>

#include "Forward.hpp"

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

	std::string			_departureTime;
	std::string			_stopTime;
public:
	Train(std::string p_name, int p_weight, float p_friction, float p_acceleration, float p_brake,
		Node* p_departure, Node* p_arrival, std::string p_depTime, std::string p_stopTime);
	~Train();

	const int 			getID() 					const { return _ID; }
	const std::string 	getName() 					const { return _name; }
	const int 			getWeight() 				const { return _weight; }
	const float			getFrictionCoefficient()	const { return _frictionCoefficient; }
	const float			getAccelerationMax() 		const { return _accelerationMax; }
	const float			getBrakeMax() 				const { return _brakeMax; }
	const Node*			getDepartureStation() 		const { return _departureStation; }
	const Node*			getArrivalStation() 		const { return _arrivalStation; }
	const std::string	getDepartureTime() 			const { return _departureTime; }
	const std::string	getStopTime() 				const { return _stopTime; }
};
