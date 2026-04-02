#include "SecretarialOffice.hpp"

SecretarialOffice::SecretarialOffice() {
}

SecretarialOffice::~SecretarialOffice() {
	for (std::vector<Form*>::iterator it = _archivedForms.begin(); it != _archivedForms.end(); ++it)
		delete *it;
}

void SecretarialOffice::archiveForm(Form* p_form) {
	_archivedForms.push_back(p_form);
}
