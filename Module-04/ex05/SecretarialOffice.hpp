#pragma once

#include "Foward.hpp"
#include "Room.hpp"

class SecretarialOffice: public Room
{
private:

	std::vector<Form*> _archivedForms;		// owning: SecretarialOffice owns these Form instances once transferred by the Secretary from the Headmaster

public:
	SecretarialOffice();
	~SecretarialOffice();

	void enterMessage() { std::cout << "Secretary's office" << std::endl; }
	void archiveForms(Form* p_form);
};
