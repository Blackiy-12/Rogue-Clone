#pragma once

#include "../Level.h"

class TestLevel : public Level
{
public:
	TestLevel(LevelHolder* Holder);

	~TestLevel();

	void generateLevel();
};

