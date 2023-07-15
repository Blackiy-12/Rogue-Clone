#pragma once

#include "../Object/Object.h"

class SelectedButton : public Object
{
public:
	SelectedButton(vec2<float> Position, vec2<float> Size);

	~SelectedButton();

	void setNewPositionAndSize(vec2<float> Position, vec2<float> Size);
};

