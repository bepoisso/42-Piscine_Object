#include "Event.hpp"

AEvent::AEvent(Time p_duration) : _duration(p_duration), _elapsed(Time(0)), _active(false), _finished(false){

}

void AEvent::update(long int dt)
{
	if (_finished)
		return ;

	if (!_active) {
		apply();
		_active = true;
	}

	_elapsed = _elapsed + dt;

	if (_elapsed >= _duration) {
		revert();
		_active = false;
		_finished = true;
	}
}

bool AEvent::isFinished() const {
	return _finished;
}
