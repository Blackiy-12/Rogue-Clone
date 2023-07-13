#include "MainMenuWorld.h"

MainMenuWorld::MainMenuWorld()
{
	this->Title = std::make_unique<Label>("Rogue", vec2<float>(0.15f, 0.05f), vec2<float>(0.7f, 0.2f));

	this->ButtonTablePtr = std::make_unique<ButtonTable>(vec2<float>(1, 1), vec2<float>(1, 1));
}

MainMenuWorld::~MainMenuWorld()
{
}
