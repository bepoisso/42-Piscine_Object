#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
private:
	std::string _requestedBy;
	std::string _reason;
	int			 _additionalRoomsCount;
	bool		 _isApproved;

public:
	NeedMoreClassRoomForm();
	void fillRequest(const std::string& p_requestedBy, const std::string& p_reason, int p_additionalRoomsCount);
	void execute();
};
