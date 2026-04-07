#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class SecretarialOffice: public Room
{
private:

	std::vector<Form*> _archivedForms;     // owning: Forms are created and deleted by SecretarialOffice

public:
	SecretarialOffice();
	~SecretarialOffice();

	void archiveForm(Form* p_form);
};
