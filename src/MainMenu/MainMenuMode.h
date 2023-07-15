#pragma once

#include "../Gamemode/Gamemode.h"
#include "MainMenuWorld.h"
#include "../Input/InputReceiver.h"


class MainMenuMode : public Gamemode, public InputReceiver
{
public:
	MainMenuMode();

	~MainMenuMode();

	void runGamemode() override;

	void receiveMessage(InputMessage Message) override;

private:

	std::unique_ptr<MainMenuWorld> World;
};

