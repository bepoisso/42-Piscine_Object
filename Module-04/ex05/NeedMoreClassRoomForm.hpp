#pragma once

#include <string>

#include "Foward.hpp"
#include "Form.hpp"
#include "Professor.hpp"
#include "Staff.hpp"

class NeedMoreClassRoomForm : public Form
{
private:
	Professor* _professor;			// non-owning: owning by School
	std::string _reason;
	int			 _additionalRoomsCount;
	bool		 _isApproved;

public:
	NeedMoreClassRoomForm();
	void fillRequest(Professor* newProfessor, const std::string& p_reason, int p_additionalRoomsCount);
	void execute();
};
