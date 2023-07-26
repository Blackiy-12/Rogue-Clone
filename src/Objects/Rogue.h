#pragma once

#include "Actor.h"
#include "../Input/InputReceiver.h"
#include "ActorsComponents/ActorLevel.h"

class Rogue : public Actor, public InputReceiver
{
public:
	Rogue(GameplayWorld* World, vec2<int> LevelPosition);

	~Rogue();

	void receiveMessage(InputMessage Message) override;

	int getCurrentHealth();

	int getMaxHealth();

	int getCurrentLevel();

protected:
	void move(vec2<int> VectorOfMovment) override;

private:
	ActorLevel RogueLevel;
};

