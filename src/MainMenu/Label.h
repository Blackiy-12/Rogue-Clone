#pragma once

#include "../Object/Object.h"

#include <string>

class Label : public Object
{
public:
	Label(std::string LabelText, vec2<float> Position, vec2<float> Size);

	~Label();

private:
	std::string LabelText;
};

