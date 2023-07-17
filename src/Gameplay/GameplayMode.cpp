#include "GameplayMode.h"

#include "../Render/Render.h"
#include "../Game.h"
#include "../Texture/TextureLoader.h"

GameplayMode::GameplayMode()
{
	TextureLoader::loadEnviromentTextures();
	this->World = std::make_unique<GameplayWorld>();
}

GameplayMode::~GameplayMode()
{
}

void GameplayMode::runGamemode()
{
	Render::getRender()->clearRenderer();

	Render::getRender()->drawRenderBuffer();

	Render::getRender()->swapRenderer();

	Input::getInput()->processInput();
}

void GameplayMode::receiveMessage(InputMessage Message)
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
