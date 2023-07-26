#include "LevelHolder.h"

#include "Test/TestLevel.h"

LevelHolder::LevelHolder(GameplayWorld* World)
{
	this->World = World;

	this->Levels.push_back(std::make_unique<TestLevel>());

	this->CurrentLevel = this->Levels.begin();

	this->CurrentLevelIndex = 0;
}

LevelHolder::~LevelHolder()
{
}

vec2<int> LevelHolder::getSpawnPosition()
{
	return this->CurrentLevel->get()->getSpawnLocation();
}
