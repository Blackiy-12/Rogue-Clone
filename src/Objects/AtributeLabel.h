#pragma once

#include "Label.h"

class AtributeLabel : public Label
{
public:
	AtributeLabel(std::string Atribute, int Value, vec2<float> Position, vec2<float> Size);

	~AtributeLabel();

	void update(int Value);

private:
	std::string Atribute;

	int AtributeValue;
};

