#pragma once

#include "../vec.h"
#include <list>
#include "../Objects/Wall.h"
#include "../Objects/Floor.h"
#include <memory>

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

	std::unique_ptr<Floor> FloorPtr;

private:
	void showAllWalls();

	void showWholeFloor();
};

