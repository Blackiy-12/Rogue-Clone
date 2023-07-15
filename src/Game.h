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

	void changeGamemode();

	void exit();

private:
	Game();

	void initNewGame();

private:
	static Game* GamePtr;

	std::shared_ptr<Gamemode> GamemodePtr;

	bool Active;
};

