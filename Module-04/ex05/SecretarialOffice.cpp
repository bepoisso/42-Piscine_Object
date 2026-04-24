#include "SecretarialOffice.hpp"
#include "Form.hpp"

SecretarialOffice::SecretarialOffice() : Room(-4, 2) {
}

SecretarialOffice::~SecretarialOffice() {
	for (std::vector<Form*>::iterator it = _archivedForms.begin(); it != _archivedForms.end(); ++it)
		delete *it;
	_archivedForms.clear();
}

void SecretarialOffice::archiveForm(Form* p_form) {
	if (!p_form)
		return;
	_archivedForms.push_back(p_form);
}
