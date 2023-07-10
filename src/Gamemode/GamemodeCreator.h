#pragma once

#include "Gamemode.h"

enum class GamemodeStatus
{
	MainMenu
};

class GamemodeCreator
{
public:
	static Gamemode* createNewGamemode();

private:
	static GamemodeStatus NewMode;
};

