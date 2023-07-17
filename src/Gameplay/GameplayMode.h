#pragma once

#include "../Gamemode/Gamemode.h"
#include "../Input/InputReceiver.h"
#include "GameplayWorld.h"
#include <memory>

class GameplayMode : public Gamemode, public InputReceiver
{
public:
	GameplayMode();

	~GameplayMode();

	void runGamemode() override;

	void receiveMessage(InputMessage Message) override;

private:

	std::unique_ptr<GameplayWorld> World;
};

