#pragma once

#include <memory>

#include "ButtonTable.h"
#include "Label.h"

class MainMenuWorld
{
public:
	MainMenuWorld();

	~MainMenuWorld();

private:
	std::unique_ptr<Label> Title;

	std::unique_ptr<ButtonTable> ButtonTablePtr;
};

