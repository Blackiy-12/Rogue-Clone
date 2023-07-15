#pragma once

#include "../Objects/Button.h"

class ButtonExit : public Button
{
public:
	ButtonExit(std::string ButtonText, vec2<float> Position, vec2<float> Size);

	~ButtonExit();

	void pressButton() override;
};

