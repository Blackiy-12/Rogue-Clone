#include "MainMenuWorld.h"

#include "../Texture/TextureLoader.h"

MainMenuWorld::MainMenuWorld()
{
	TextureLoader::loadUITextures();

	this->Title = std::make_unique<Label>("Rogue", vec2<float>(0.15f, 0.05f), vec2<float>(0.7f, 0.2f));

	this->ButtonTablePtr = std::make_unique<ButtonTable>(vec2<float>(0.3f, 0.3f), vec2<float>(0.4f, 0.60f));

	this->ButtonTablePtr->addButton("Play", ButtonType::PLAY);

	this->ButtonTablePtr->addButton("Exit", ButtonType::EXIT);
}

MainMenuWorld::~MainMenuWorld()
{
}
