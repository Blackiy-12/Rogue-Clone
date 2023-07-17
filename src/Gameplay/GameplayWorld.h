#pragma once

#include "LevelHolder.h"
#include <memory>

class GameplayWorld
{
public:
	GameplayWorld();

	~GameplayWorld();

private:
	std::unique_ptr<LevelHolder> Levels;
};

