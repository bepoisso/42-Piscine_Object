#include "NeedMoreClassRoomForm.hpp"

#include <iostream>

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(NeedMoreClassRoom), _additionalRoomsCount(0), _isApproved(false) {
}

void NeedMoreClassRoomForm::fillRequest(Professor* newProfessor, const std::string& p_reason, int p_additionalRoomsCount) {
	_professor = newProfessor;
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
	Classroom* newClassroom = new Classroom();
	
	Headmaster* mediator = _professor->getheadmasterMediator();
	mediator->addClassroomList(newClassroom);

	newClassroom->assignCourse(_professor->getCourse());
	_professor->getCourse()->setClassroom(newClassroom);
	std::cout << "Classroom extension approved: " << _additionalRoomsCount
		<< " room(s) requested by " << _professor->getName() << " (reason: " << _reason << ")" << std::endl;
}
