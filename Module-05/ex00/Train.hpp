#pragma once

#include <string>
#include <iostream>

#include "Forward.hpp"

#include "Node.hpp"
#include "Rail.hpp"
#include "Movement.hpp"
#include "Time.hpp"
#include "Clock.hpp"

class Train: public AMovement, public AClock {
private:
	const int			_ID;
	const std::string	_name;

	const Node*			_departureStation;				// non-owning: owned by Simulation
	const Node*			_arrivalStation;				// non-owning: owned by Simulation

	Rail*				_currentRail;
	Node*				_direction;
	bool				_isOnNode;

	Time			_departureTime;
	Time			_stopTime;
public:
	Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake,
		Node* p_departure, Node* p_arrival, std::string p_depTime, std::string p_stopTime);
	~Train();

	int 			getID() 					const { return _ID; }
	std::string 	getName() 					const { return _name; }
	double			getCurrentSpeedLimit()		const;
	Node*			getDepartureStation()		const { return const_cast<Node*>(_departureStation); }
	Node*			getArrivalStation()			const { return const_cast<Node*>(_arrivalStation); }
	Time			getDepartureTime()			const { return _departureTime; }
	Time			getStopTime()				const { return _stopTime; }
	Rail*			getCurrentRail()			const { return _currentRail; }
	Node*			getDirectionNode()			const { return _direction; }
	bool			isOnNode()					const { return _isOnNode; }

	void			setCurrentRail(Rail* r)	{ _currentRail = r; }
	void			setNextNode(Node* n) { _direction = n; }
	void			setIsOnNode(bool b) { _isOnNode = b; }

	void update(long int p_dt);
};
