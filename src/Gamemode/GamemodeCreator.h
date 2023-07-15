#pragma once

#include "Gamemode.h"
#include <memory>

enum class GamemodeStatus
{
	MainMenu,
	Gameplay
};

class GamemodeCreator
{
public:
	static std::shared_ptr<Gamemode> createNewGamemode();

	static GamemodeStatus NewMode;
};

