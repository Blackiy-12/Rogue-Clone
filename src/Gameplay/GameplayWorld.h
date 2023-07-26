#pragma once

#include "LevelHolder.h"
#include "../Objects/Rogue.h"
#include "../Objects/HealthUI.h"
#include "../Objects/AtributeLabel.h"
#include <memory>

class GameplayWorld
{
public:
	GameplayWorld();

	~GameplayWorld();

private:
	std::unique_ptr<LevelHolder> Levels;

	std::unique_ptr<Rogue> RoguePtr;

	std::unique_ptr<AtributeLabel> RogueLevelUI;

	std::unique_ptr<HealthUI> HealthUIPtr;

	std::unique_ptr<AtributeLabel> StrengthUI;

	std::unique_ptr<AtributeLabel> GoldUI;
	
	std::unique_ptr<AtributeLabel> ArmorUI;
};

