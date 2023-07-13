#include "MainMenuMode.h"

#include "../Render/Render.h"

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
}
