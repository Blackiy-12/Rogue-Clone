#pragma once

#include "Label.h"

class Button : public Label
{
public:
	Button(std::string ButtonText, vec2<float> Position, vec2<float> Size);

	~Button();
};

