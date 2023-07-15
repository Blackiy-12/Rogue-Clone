#pragma once

#include "Label.h"

class Button : public Label
{
public:
	Button(std::string ButtonText, vec2<float> Position, vec2<float> Size);

	~Button();

	vec2<float> getPosition();

	vec2<float> getSize();

	void setNewPositionAndSize(vec2<float> Position, vec2<float> Size);

	void virtual pressButton();
};

