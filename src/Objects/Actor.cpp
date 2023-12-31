#include "Actor.h"


Actor::Actor(Level* World, vec2<int> LevelPosition) : World(World), LevelPosition(LevelPosition), LevelSystem(), Armor(), Strength(), Damage(1, 20)
{
}

Actor::~Actor()
{
}

vec2<int> Actor::getLevelPosition()
{
	return this->LevelPosition;
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

int Actor::getCurrentStrength()
{
	return this->Strength.getStrength();
}

#include <iostream> // TODO: delete
void Actor::applyDamage(int DamageValue)
{

	std::cout << "HIT" << DamageValue << '\n';
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

void Actor::atack(vec2<int> AtackPosition)
{
}
