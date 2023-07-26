#pragma once

#include "Actor.h"
#include "../Input/InputReceiver.h"
#include "ActorsComponents/Gold.h"

class Rogue : public Actor, public InputReceiver
{
public:
	Rogue(Level* World, vec2<int> LevelPosition);

	~Rogue();

	void receiveMessage(InputMessage Message) override;

	int getGoldValue();

protected:
	void move(vec2<int> VectorOfMovment) override;

private:

	Gold GoldValue;
};

