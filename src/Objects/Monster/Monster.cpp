#include "Monster.h"

#include "../../Texture/TextueNames.h"

Monster::Monster(Level* World, vec2<int> LevelPosition) : Actor(World, LevelPosition)
{
	this->Graphic = std::make_unique<GraphicOfObject>(CellSize, vec2<float>{ 0.0f, 0.0f }, TextureNames[TEXURE_NAME_INDEX::STAIRS], 0, 2);

	this->updatePosition(this->LevelPosition);

	this->Health = std::make_unique<HealthComponent>();
}

Monster::~Monster()
{
}

void Monster::move(vec2<int> VectorOfMovment)
{
}
