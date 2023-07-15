#pragma once

#include "../Objects/Button.h"

class ButtonPlay : public Button
{
public:
	ButtonPlay(std::string ButtonText, vec2<float> Position, vec2<float> Size);
	
	~ButtonPlay();

	void pressButton() override;
};

