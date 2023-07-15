#include "ButtonPlay.h"

#include "../Gamemode/GamemodeCreator.h"
#include "../Game.h"

ButtonPlay::ButtonPlay(std::string ButtonText, vec2<float> Position, vec2<float> Size) : Button(ButtonText, Position, Size)
{
}

ButtonPlay::~ButtonPlay()
{
}

void ButtonPlay::pressButton()
{
	GamemodeCreator::NewMode = GamemodeStatus::Gameplay;
	Game::getGamePointer()->changeGamemode();
}
