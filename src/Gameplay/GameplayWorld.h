#pragma once

#include "LevelHolder.h"
#include "../Objects/Rogue.h"
#include "../Objects/HealthUI.h"
#include <memory>

class GameplayWorld
{
public:
	GameplayWorld();

	~GameplayWorld();

private:
	std::unique_ptr<LevelHolder> Levels;

	std::unique_ptr<Rogue> RoguePtr;

	std::unique_ptr<HealthUI> HealthUIPtr;
};

