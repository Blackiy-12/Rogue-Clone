#include "Room.h"

Room::Room(vec2<int> TopLeftPosition, vec2<int> Size) : TopLeftPosition(TopLeftPosition), Size(Size), Visiable(false)
{
}

Room::~Room()
{
}

void Room::setVisible()
{
	this->Visiable = true;
	this->showAllWalls();
}

void Room::showAllWalls()
{
	vec2<float> WallPosition = { 0, 0 };
	vec2<float> WallSize = { 0, 0 };


	WallPosition = { 0.05f + (TopLeftPosition.x * CellSize.x), 0.1f + (TopLeftPosition.y * CellSize.y) };
	WallSize = { CellSize.x, CellSize.y };
	this->Walls.push_back(std::make_unique<Wall>(WallType::CORNER, CornerPosition::TOP_LEFT, WallPosition, WallSize));


	WallPosition = { 0.05f + ((TopLeftPosition.x + 1 - 0.2f) * CellSize.x), 0.1f + (TopLeftPosition.y * CellSize.y) };
	WallSize = { CellSize.x * (Size.x - 1 + 0.4f), CellSize.y };
	this->Walls.push_back(std::make_unique<Wall>(WallType::HORIZONTAL, WallPosition, WallSize));


	WallPosition = { 0.05f + ((TopLeftPosition.x + Size.x) * CellSize.x), 0.1f + (TopLeftPosition.y * CellSize.y) };
	WallSize = { CellSize.x, CellSize.y };
	this->Walls.push_back(std::make_unique<Wall>(WallType::CORNER, CornerPosition::TOP_RIGHT, WallPosition, WallSize));


	WallPosition = { 0.05f + ((TopLeftPosition.x + Size.x) * CellSize.x), 0.1f + ((TopLeftPosition.y + 1 - 0.2f) * CellSize.y) };
	WallSize = { CellSize.x, CellSize.y * (Size.y - 1 + 0.4f) };
	this->Walls.push_back(std::make_unique<Wall>(WallType::VERTICAL, WallPosition, WallSize));


	WallPosition = { 0.05f + ((TopLeftPosition.x + Size.x) * CellSize.x), 0.1f + ((TopLeftPosition.y + Size.y) * CellSize.y ) };
	WallSize = { CellSize.x, CellSize.y };
	this->Walls.push_back(std::make_unique<Wall>(WallType::CORNER, CornerPosition::BOTTOM_RIGHT, WallPosition, WallSize));


	WallPosition = { 0.05f + ((TopLeftPosition.x + 1 - 0.2f) * CellSize.x), 0.1f + (TopLeftPosition.y + Size.y * CellSize.y) };
	WallSize = { CellSize.x * (Size.x - 1 + 0.4f), CellSize.y };
	this->Walls.push_back(std::make_unique<Wall>(WallType::HORIZONTAL, WallPosition, WallSize));


	WallPosition = { 0.05f + (TopLeftPosition.x * CellSize.x), 0.1f + ((TopLeftPosition.y + Size.y) * CellSize.y ) };
	WallSize = { CellSize.x, CellSize.y };
	this->Walls.push_back(std::make_unique<Wall>(WallType::CORNER, CornerPosition::BOTTOM_LEFT, WallPosition, WallSize));


	WallPosition = { 0.05f + ((TopLeftPosition.x) * CellSize.x), 0.1f + ((TopLeftPosition.y + 1 - 0.2f) * CellSize.y) };
	WallSize = { CellSize.x, CellSize.y * (Size.y - 1 + 0.4f) };
	this->Walls.push_back(std::make_unique<Wall>(WallType::VERTICAL, WallPosition, WallSize));
}
