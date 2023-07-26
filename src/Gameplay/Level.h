#pragma once

#include <list>
#include "Room.h"
#include <memory>

const vec2<int> LEVEL_SIZE = {74, 19};

const vec2<float> LevelTopLeftPosition = { 0.05f, 0.1f };

const vec2<float> CellSize = { 0.9f / 75, 0.8f / 20 };

class Level
{
public:
	Level();

	~Level();

	void generateLevel();
	
	vec2<int> getSpawnLocation();
protected:
	std::list<std::unique_ptr<Room>> Rooms;

	vec2<int> SpawnLocation;
};

