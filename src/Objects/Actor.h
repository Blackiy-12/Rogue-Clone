#pragma once

#include "../Object/Object.h"
#include "../vec.h"
#include "ActorsComponents/HealthComponent.h"
#include "ActorsComponents/ActorLevel.h"
#include "ActorsComponents/ActorArmor.h"
#include "ActorsComponents/ActorStrength.h"
#include "../Gameplay/Level.h"
#include <memory>

class Actor : public Object
{
public:
	Actor(Level* World, vec2<int> LevelPosition);

	~Actor();

	vec2<int> getLevelPosition();

	int getCurrentHealth();

	int getMaxHealth();

	int getCurrentLevel();

	int getCurrentArmor();

	int getCurrentStrength();

protected:
	Level* World;

	vec2<int> LevelPosition;

	std::unique_ptr<HealthComponent> Health;

	ActorLevel LevelSystem;

	ActorArmor Armor;

	ActorStrength Strength;

protected:
	virtual void move(vec2<int> VectorOfMovment);

	virtual void updatePosition(vec2<int> NewPosition);

};

