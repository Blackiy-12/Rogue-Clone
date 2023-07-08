#pragma once

#include "../World/World.h"

#include <memory>

class Render;

class Gamemode
{
public:
	Gamemode() : WorldPtr(nullptr) {}

	virtual ~Gamemode() = 0;

	virtual void updateWorld(Render RenderPtr) = 0;

protected:
	std::unique_ptr<World> WorldPtr;
};

