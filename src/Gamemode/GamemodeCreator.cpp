#include "GamemodeCreator.h"

#include "../MainMenu/MainMenuMode.h"

GamemodeStatus GamemodeCreator::NewMode = GamemodeStatus::MainMenu;

std::shared_ptr<Gamemode> GamemodeCreator::createNewGamemode()
{
	switch (GamemodeCreator::NewMode)
	{
	case GamemodeStatus::MainMenu:
		return std::make_shared<MainMenuMode>();
	default:
		break;
	}
}
