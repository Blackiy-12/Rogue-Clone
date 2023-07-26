#include "Wall.h"

#include "../Texture/TextureCreator.h"
#include "../Texture/TextueNames.h"

Wall::Wall(WallType Type, vec2<float> TopLeftPosition, vec2<float> Size)
{
	this->Type = Type;
	this->WallSize = 0;

	switch (Type)
	{
	case WallType::VERTICAL:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::STRAIGHT_WALL], 90, 0);
		break;
	case WallType::HORIZONTAL:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::STRAIGHT_WALL], 0, 0);
		break;
	case WallType::CORNER:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::CORNER_WALL], 0, 0);
		break;
	case WallType::DOOR:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::DOOR], 0, 0);
		break;
	default:
		break;
	}

}

Wall::Wall(WallType Type, CornerPosition Posotion, vec2<float> TopLeftPosition, vec2<float> Size)
{
	this->Type = Type;
	this->WallSize = 0;

	switch (Posotion)
	{
	case CornerPosition::TOP_LEFT:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::CORNER_WALL], 180, 0);
		break;
	case CornerPosition::TOP_RIGHT:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::CORNER_WALL], 270, 0);
		break;
	case CornerPosition::BOTTOM_LEFT:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::CORNER_WALL], 90, 0);
		break;
	case CornerPosition::BOTTOM_RIGHT:
		this->Graphic = std::make_unique<GraphicOfObject>(Size, TopLeftPosition, TextureNames[TEXURE_NAME_INDEX::CORNER_WALL], 0, 0);
		break;
	default:
		break;
	}

}

Wall::~Wall()
{
}

void Wall::setNewWallSize(int NewWallSize)
{
}

int Wall::getWallSize()
{
	return this->WallSize;
}
