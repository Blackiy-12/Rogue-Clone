#pragma once

#include "../Object/Object.h"
#include "Button.h"
#include <list>
#include <memory>

class ButtonTable
{
public:
	ButtonTable(vec2<float> TableCoordinate, vec2<float> Size);

	~ButtonTable();

	void addButton(std::string ButtonText);

private:
	vec2<float> TopLeftPosition;

	vec2<float> ButtonSize;

	std::list<std::unique_ptr<Button>> Buttons;

	int ButtonSelected;
};

