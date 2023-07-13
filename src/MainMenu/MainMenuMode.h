#pragma once

#include "../Gamemode/Gamemode.h"
#include "MainMenuWorld.h"


class MainMenuMode : public Gamemode
{
public:
	MainMenuMode();

	~MainMenuMode();

	void runGamemode() override;

private:

	std::unique_ptr<MainMenuWorld> World;
};

