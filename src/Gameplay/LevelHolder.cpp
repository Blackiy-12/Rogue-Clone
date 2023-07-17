#include "LevelHolder.h"

#include "Test/TestLevel.h"

LevelHolder::LevelHolder(GameplayWorld* World)
{
	this->World = World;
	this->Levels.push_back(std::make_unique<TestLevel>());
}

LevelHolder::~LevelHolder()
{
}
