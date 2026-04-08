#include "NeedMoreClassRoomForm.hpp"

#include <iostream>

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(NeedMoreClassRoom), _additionalRoomsCount(0), _isApproved(false) {
}

void NeedMoreClassRoomForm::fillRequest(const std::string& p_requestedBy, const std::string& p_reason, int p_additionalRoomsCount) {
	_requestedBy = p_requestedBy;
	_reason = p_reason;
	_additionalRoomsCount = p_additionalRoomsCount;
	setIsDataFilled(true);
}

void NeedMoreClassRoomForm::execute() {
	if (!getIsSigned()) {
		std::cout << "NeedMoreClassRoomForm execution refused: form is not signed" << std::endl;
		return;
	}
	if (!getIsDataFilled()) {
		std::cout << "NeedMoreClassRoomForm execution refused: missing request data" << std::endl;
		return;
	}
	_isApproved = true;
	std::cout << "Classroom extension approved: " << _additionalRoomsCount
		<< " room(s) requested by " << _requestedBy << " (reason: " << _reason << ")" << std::endl;
}
