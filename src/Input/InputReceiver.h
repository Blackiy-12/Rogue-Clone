#pragma once

#include "Input.h"

class InputReceiver
{
public:
	InputReceiver() { Input::getInput()->subscribe(this); }

	~InputReceiver() { Input::getInput()->unsubscribe(this); }

	virtual void receiveMessage(InputMessage Message) = 0;
};

