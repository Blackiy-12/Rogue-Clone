#include "GamemodeCreator.h"

#include "../MainMenu/MainMenuMode.h"

GamemodeStatus GamemodeCreator::NewMode = GamemodeStatus::MainMenu;

Gamemode* GamemodeCreator::createNewGamemode()
{
	Gamemode* NewMode = nullptr;

	switch (GamemodeCreator::NewMode)
	{
	case GamemodeStatus::MainMenu:
		NewMode = new MainMenuMode();
		break;
	default:
		break;
	}

	return NewMode;
}
