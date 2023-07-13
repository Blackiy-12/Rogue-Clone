#pragma once

#include "Gamemode.h"
#include <memory>

enum class GamemodeStatus
{
	MainMenu
};

class GamemodeCreator
{
public:
	static std::shared_ptr<Gamemode> createNewGamemode();

private:
	static GamemodeStatus NewMode;
};

