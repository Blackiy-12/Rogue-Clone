#include "Floor.h"

Floor::Floor(vec2<float> Position, vec2<float> Size, vec2<int> FloorSize) : FloorSize(FloorSize)
{
	this->Graphic = std::make_unique<GraphicOfObject>(Size, Position, this->FloorSize, 0);
}

Floor::~Floor()
{
}
