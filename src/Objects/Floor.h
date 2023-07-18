#pragma once

#include "../Object/Object.h"

class Floor : public Object
{
public:
	Floor(vec2<float> Position, vec2<float> Size, vec2<int> FloorSize);

	~Floor();
	
private:
	vec2<int> FloorSize;

};

