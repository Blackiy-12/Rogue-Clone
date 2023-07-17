#pragma once

#include "../vec.h"
#include <list>
#include "../Objects/Wall.h"
#include <memory>

const vec2<float> CellSize = { 0.9f / 75, 0.8f / 20 };

class Room
{
public:
	Room(vec2<int> TopLeftPosition, vec2<int> Size);

	~Room();

	void setVisible();

private:
	vec2<int> TopLeftPosition;
	
	vec2<int> Size;

	bool Visiable;

	std::list<std::unique_ptr<Wall>> Walls;

private:
	void showAllWalls();
};

