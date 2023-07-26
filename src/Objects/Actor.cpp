#include "Actor.h"

#include "../Gameplay/Level.h"

Actor::Actor(GameplayWorld* World, vec2<int> LevelPosition) : World(World), LevelPosition(LevelPosition), LevelSystem(), Armor()
{
}

Actor::~Actor()
{
}

int Actor::getCurrentHealth()
{
	return this->Health->getCurrentHP();
}

int Actor::getMaxHealth()
{
	return this->Health->getMaxHP();
}

int Actor::getCurrentLevel()
{
	return this->LevelSystem.getCurrentLevel();
}

int Actor::getCurrentArmor()
{
	return this->Armor.getArmorClass();
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
