#pragma once

#include "../Object/Object.h"
#include "../vec.h"
#include "ActorsComponents/HealthComponent.h"
#include "ActorsComponents/ActorLevel.h"
#include "ActorsComponents/ActorArmor.h"
#include <memory>

class GameplayWorld;

class Actor : public Object
{
public:
	Actor(GameplayWorld* World, vec2<int> LevelPosition);

	~Actor();

	int getCurrentHealth();

	int getMaxHealth();

	int getCurrentLevel();

	int getCurrentArmor();

protected:
	GameplayWorld* World;

	vec2<int> LevelPosition;

	std::unique_ptr<HealthComponent> Health;

	ActorLevel LevelSystem;

	ActorArmor Armor;

protected:
	virtual void move(vec2<int> VectorOfMovment);

	virtual void updatePosition(vec2<int> NewPosition);

};

