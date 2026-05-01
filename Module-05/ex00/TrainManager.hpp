#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Forward.hpp"
#include "Train.hpp"
#include "Clock.hpp"

class TrainManager : public AClock {
private:
	std::vector<Train*> _trains;

public:
	TrainManager(std::vector<Train*> p_trains, long int p_startTime);
	~TrainManager();

	std::vector<int> getTrainID();
	Train* getTrain(int p_id);

	void update(long int p_dt);
	void init(long int p_st);
};
