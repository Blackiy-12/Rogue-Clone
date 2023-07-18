#pragma once

#include <list>
#include "Room.h"
#include <memory>

const vec2<int> LEVEL_SIZE = {74, 19};

class Level
{
public:
	Level();

	~Level();

	void generateLevel();

protected:
	std::list<std::unique_ptr<Room>> Rooms;
};

