#pragma once

#include <iostream>

#include "Forward.hpp"

class APosition {
private:
	const bool _isStation;
	const bool _isNode;
	const bool _isRail;
public:
	APosition(bool p_isStation, bool p_isNode, bool p_isRail);
	virtual ~APosition();

	bool getIsStation() const { return _isStation; }
	bool getIsNode() const { return _isNode; }
	bool getIsRail() const { return _isRail; }
};

