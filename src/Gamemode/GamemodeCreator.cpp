#include "GamemodeCreator.h"

#include "../MainMenu/MainMenuMode.h"
#include "../Gameplay/GameplayMode.h"

GamemodeStatus GamemodeCreator::NewMode = GamemodeStatus::MainMenu;

std::shared_ptr<Gamemode> GamemodeCreator::createNewGamemode()
{
	switch (GamemodeCreator::NewMode)
	{
	case GamemodeStatus::MainMenu:
		return std::make_shared<MainMenuMode>();
	case GamemodeStatus::Gameplay:
		return std::make_shared<GameplayMode>();
	default:
		break;
	}
}
