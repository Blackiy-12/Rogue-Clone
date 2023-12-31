#pragma once

#include "Level.h"
#include <list>
#include <memory>

class GameplayWorld;
class Rogue;

class LevelHolder
{
public:
	LevelHolder(GameplayWorld* World);

	~LevelHolder();

	vec2<int> getSpawnPosition();

	Level* getCurrentLevel();

	Rogue* getRogue();

private:
	const int MAX_LEVEL = 10;

	GameplayWorld* World;

	std::list<std::unique_ptr<Level>> Levels;

	int CurrentLevelIndex;

	std::list<std::unique_ptr<Level>>::iterator CurrentLevel;
};

