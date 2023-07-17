#include "GameplayWorld.h"

#include "LevelHolder.h"

GameplayWorld::GameplayWorld()
{
	this->Levels = std::make_unique<LevelHolder>(this);
}

GameplayWorld::~GameplayWorld()
{
}
