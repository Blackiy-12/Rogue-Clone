#include "Actor.h"

#include "../Gameplay/Level.h"

Actor::Actor(GameplayWorld* World, vec2<int> LevelPosition) : World(World), LevelPosition(LevelPosition)
{
}

Actor::~Actor()
{
}

void Actor::move(vec2<int> VectorOfMovment)
{
}

void Actor::updatePosition(vec2<int> NewPosition)
{
	this->LevelPosition = NewPosition;

	vec2<float> ScreenPosition = { 0, 0 };
	ScreenPosition.x = LevelTopLeftPosition.x + NewPosition.x * CellSize.x;
	ScreenPosition.y = LevelTopLeftPosition.y + NewPosition.y * CellSize.y;

	this->Graphic->setNewPosition(ScreenPosition);
}
