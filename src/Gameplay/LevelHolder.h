#pragma once

#include "Level.h"
#include <list>
#include <memory>

class GameplayWorld;

class LevelHolder
{
public:
	LevelHolder(GameplayWorld* World);

	~LevelHolder();

private:
	GameplayWorld* World;

	std::list<std::unique_ptr<Level>> Levels;
};

