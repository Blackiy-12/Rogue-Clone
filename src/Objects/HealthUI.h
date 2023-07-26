#pragma once

#include "Label.h"

class HealthUI : public Label
{
public:
	HealthUI(int Health, int HealthMax, vec2<float> Position, vec2<float> Size);

	~HealthUI();

private:

	int Health;

	int MaxHealth;
};

