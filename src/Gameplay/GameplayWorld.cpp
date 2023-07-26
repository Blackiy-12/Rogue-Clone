#include "GameplayWorld.h"

#include "LevelHolder.h"

const vec2<float> UISize( 0.16f, 0.1f);

const vec2<float> RogueLevelUIPosition( 0.0f, 0.9f);

const vec2<float> HealthUIPosition( 0.21f, 0.9f);

GameplayWorld::GameplayWorld()
{
	this->Levels = std::make_unique<LevelHolder>(this);

	this->RoguePtr = std::make_unique<Rogue>(this, this->Levels->getSpawnPosition());

	this->RogueLevelUI = std::make_unique<Label>(std::string("Level:" + std::to_string(this->RoguePtr->getCurrentLevel())), RogueLevelUIPosition, UISize);

	this->HealthUIPtr = std::make_unique<HealthUI>(this->RoguePtr->getCurrentHealth(), this->RoguePtr->getMaxHealth(), HealthUIPosition, UISize);
}

GameplayWorld::~GameplayWorld()
{
}
