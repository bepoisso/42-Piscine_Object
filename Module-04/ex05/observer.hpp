#pragma once

#include "Types.hpp"


class IObserver {
public:
	bool _isOnBreak = true;
	virtual ~IObserver() {}
	virtual void onBell(Event event) = 0;
};
