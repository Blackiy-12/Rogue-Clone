#include "MainMenuMode.h"

#include "../Render/Render.h"
#include "../Input/Input.h"
#include "../Game.h"

MainMenuMode::MainMenuMode()
{
	this->World = std::make_unique<MainMenuWorld>();
}

MainMenuMode::~MainMenuMode()
{
}

void MainMenuMode::runGamemode()
{
	Render::getRender()->clearRenderer();

	Render::getRender()->drawRenderBuffer();

	Render::getRender()->swapRenderer();

	Input::getInput()->processInput();
}

void MainMenuMode::receiveMessage(InputMessage Message)
{
	if (Message.Type == InputType::WINDOWS)
	{
		switch (Message.WindowCode)
		{
		case WindowEvent::RESIZE:
			Input::getInput()->stopGettingInput();
			break;
		case WindowEvent::CLOSED:
			Game::getGamePointer()->exit();
			Input::getInput()->stopGettingInput();
			break;
		default:
			break;
		}

	}
}
