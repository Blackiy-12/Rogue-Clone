#pragma once

#include "Gamemode/Gamemode.h"
#include <memory>

class Game
{
public:

	Game(Game& other) = delete;

	void operator=(const Game&) = delete;

	static Game* getGamePointer();

	void start();

private:
	Game();

	void initNewGame();

private:
	static Game* GamePtr;

	std::unique_ptr<Gamemode> GamemodePtr;
};

