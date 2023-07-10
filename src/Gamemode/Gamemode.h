#pragma once

#include <memory>

class Gamemode
{
public:
	Gamemode() {}

	virtual ~Gamemode() = 0;

	virtual void runGamemode() = 0;
};

