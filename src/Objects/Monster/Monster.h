#pragma once

#include "../Actor.h"

class Monster : public Actor
{
public:
	Monster(Level* World, vec2<int> LevelPosition);

	~Monster();

protected:
	void move(vec2<int> VectorOfMovment) override;
};

