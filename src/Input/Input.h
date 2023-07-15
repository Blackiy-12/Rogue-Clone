#pragma once

#include <list>

#include <SDL.h>

class InputReceiver;

struct InputMessage;

class Input
{
public:
	Input(Input& other) = delete;

	void operator=(const Input&) = delete;

	static Input* getInput();

	void subscribe(InputReceiver* NewSubscriber);

	void unsubscribe(InputReceiver* Subscribers);

	void processInput();

	void stopGettingInput();

private:
	static Input* InputPtr;

	std::list<InputReceiver*> Subscribers;

	bool GettingInput;
private:
	Input();

	~Input();

	void sendMessage(InputMessage Message);
};


enum class InputType
{
	NONE,
	WINDOWS,
	KEYBOARD
};

enum class WindowEvent
{
	NONE,
	RESIZE,
	CLOSED
};

struct InputMessage
{
	InputType Type = InputType::NONE;
	SDL_Keycode KeyCode = SDLK_UNKNOWN;
	WindowEvent WindowCode = WindowEvent::NONE;
};

