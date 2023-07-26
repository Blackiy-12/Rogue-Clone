#include "AtributeLabel.h"

AtributeLabel::AtributeLabel(std::string Atribute, int Value, vec2<float> Position, vec2<float> Size) : Label("", Position, Size), Atribute(Atribute), AtributeValue(Value-1)
{
	this->update(Value);
}

AtributeLabel::~AtributeLabel()
{
}

void AtributeLabel::update(int Value)
{
	if (this->AtributeValue == Value)
		return;

	this->AtributeValue = Value;

	std::string NewText = Atribute + ':';

	NewText += std::to_string(this->AtributeValue);

	this->updateText(NewText);
}
