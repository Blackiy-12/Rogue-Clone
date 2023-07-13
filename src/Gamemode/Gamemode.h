#pragma once

#include <memory>

class Gamemode
{
public:
	Gamemode() {}

	virtual ~Gamemode() {};

	virtual void runGamemode() = 0;
};

