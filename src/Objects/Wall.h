#pragma once

#include "../Object/Object.h"
#include "../vec.h"

enum class WallType
{
	NONE,
	VERTICAL,
	HORIZONTAL,
	CORNER,
	DOOR
};

enum class CornerPosition
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT
};

class Wall : public Object
{
public:
	Wall(WallType Type, vec2<float> TopLeftPosition, vec2<float> Size);

	Wall(WallType Type, CornerPosition Posotion, vec2<float> TopLeftPosition, vec2<float> Size);

	~Wall();

	void setNewWallSize(int NewWallSize);

	int getWallSize();

private:
	int WallSize;

	WallType Type;
};

