#pragma once

#include "../Object/Object.h"
#include "../vec.h"
#include "ActorsComponents/HealthComponent.h"
#include "ActorsComponents/ActorLevel.h"
#include "ActorsComponents/ActorArmor.h"
#include "ActorsComponents/ActorStrength.h"
#include "ActorsComponents/AtackComponent.h"
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

	void applyDamage(int DamageValue);

protected:
	Level* World;

	vec2<int> LevelPosition;

	std::unique_ptr<HealthComponent> Health;

	ActorLevel LevelSystem;

	ActorArmor Armor;

	ActorStrength Strength;

	AtackComponent Damage;

protected:
	virtual void move(vec2<int> VectorOfMovment);

	virtual void updatePosition(vec2<int> NewPosition);

	virtual void atack(vec2<int> AtackPosition);
};

