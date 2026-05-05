#pragma once

#include <string>
#include <iostream>

#include "Forward.hpp"

#include "Node.hpp"
#include "Rail.hpp"
#include "Movement.hpp"
#include "Time.hpp"
#include "Clock.hpp"
#include "TrainManager.hpp"

class Train: public AMovement, public AClock {
private:
	const int			_ID;
	const std::string	_name;

	const Node*			_departureStation;				// non-owning: owned by Simulation
	const Node*			_arrivalStation;				// non-owning: owned by Simulation

	std::vector<Node*>	_path;
	size_t				_pathIndex;
	TrainManager*		_mediator;

	Rail*				_currentRail;
	Node*				_from;
	Node*				_to;
	bool				_hasStart;
	bool				_finish;

	Time				_departureTime;
	Time				_stopTime;
	Time				_waitingTime;
public:
	Train(std::string p_name, int p_weight, double p_friction, double p_acceleration, double p_brake,
		Node* p_departure, Node* p_arrival, std::string p_depTime, std::string p_stopTime);
	~Train();

	int 			getID() 					const	{ return _ID; }
	std::string 	getName() 					const	{ return _name; }
	double			getCurrentSpeedLimit()		const;
	Node*			getDepartureStation()		const	{ return const_cast<Node*>(_departureStation); }
	Node*			getArrivalStation()			const	{ return const_cast<Node*>(_arrivalStation); }
	Time			getDepartureTime()			const	{ return _departureTime; }
	Time			getStopTime()				const	{ return _stopTime; }
	Rail*			getCurrentRail()			const	{ return _currentRail; }
	Node*			getNodeFrom()				const	{ return _from; }
	Node*			getNodeTo()					const	{ return _to; }
	bool			isFinished()				const	{ return _finish; }

	void			setCurrentRail(Rail* r)				{ _currentRail = r; }
	void			setNodeFrom(Node* n)				{ _from = n; }
	void			setNodeTo(Node* n)					{ _to = n; }
	void			setPath(std::vector<Node*> p_path)	{ _path = p_path; }
	void			setMediator(TrainManager* p_med)	{ _mediator = p_med; }

	void goToNextRail();
	void update(long int p_dt);
	void printState();

	void D_printPath() { std::cout<<"___PRINT_PATH_"<<getID()<<"___\n";for(std::vector<Node*>::iterator i=_path.begin();i!=_path.end();++i) std::cout<<(*i)->getName()<<std::endl;std::cout<<"___PRINT_PATH_END___\n"; }
};
