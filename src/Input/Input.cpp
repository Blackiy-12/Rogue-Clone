#include "Input.h"

#include "InputReceiver.h"

Input* Input::InputPtr = nullptr;

Input* Input::getInput()
{
	if (Input::InputPtr == nullptr)
		Input::InputPtr = new Input();

	return Input::InputPtr;
}

void Input::subscribe(InputReceiver* NewSubscriber)
{
	this->Subscribers.push_back(NewSubscriber);
}

void Input::unsubscribe(InputReceiver* Subscribers)
{
	this->Subscribers.remove(Subscribers);
}

void Input::processInput()
{
	InputMessage Message;
	SDL_Event Event;

	this->GettingInput = true;

	while (SDL_WaitEvent(&Event) != 0 && this->GettingInput) 
	{
		if (Event.type == SDL_WINDOWEVENT)
		{
			switch (Event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_MOVED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				Message.Type = InputType::WINDOWS;
				Message.KeyCode = SDLK_UNKNOWN;
				Message.WindowCode = WindowEvent::RESIZE;
				this->sendMessage(Message);

				break;

			case SDL_WINDOWEVENT_CLOSE:
				Message.Type = InputType::WINDOWS;
				Message.KeyCode = SDLK_UNKNOWN;
				Message.WindowCode = WindowEvent::CLOSED;
				this->sendMessage(Message);

				break;
			default:
				break;
			}
		}

		else if (Event.type == SDL_KEYDOWN)
		{
			Message.Type = InputType::KEYBOARD;
			Message.KeyCode = Event.key.keysym.sym;
			Message.WindowCode = WindowEvent::NONE;
			this->sendMessage(Message);
		}
	}
}

void Input::stopGettingInput()
{
	this->GettingInput = false;
}

Input::Input()
{
	this->GettingInput = false;
}

Input::~Input()
{
}

void Input::sendMessage(InputMessage Message)
{
	for (auto Subscriber : this->Subscribers)
	{
		Subscriber->receiveMessage(Message);
	}
}
