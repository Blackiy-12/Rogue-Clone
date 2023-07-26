#include "HealthUI.h"

HealthUI::HealthUI(int Health, int HealthMax, vec2<float> Position, vec2<float> Size) : Label("", Position, Size), Health(Health), MaxHealth(HealthMax)
{
	std::string Text = "Hits:";

	Text.append(std::to_string(Health));

	Text.append('(' + std::to_string(MaxHealth) + ')');

	this->updateText(Text);
}

HealthUI::~HealthUI()
{
}
