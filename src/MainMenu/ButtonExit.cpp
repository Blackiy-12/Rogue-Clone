#include "ButtonExit.h"

#include "../Game.h"

ButtonExit::ButtonExit(std::string ButtonText, vec2<float> Position, vec2<float> Size) : Button(ButtonText, Position, Size)
{
}

ButtonExit::~ButtonExit()
{
}

void ButtonExit::pressButton()
{
	Game::getGamePointer()->exit();
}
