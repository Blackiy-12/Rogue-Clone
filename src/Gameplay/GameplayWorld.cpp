#include "GameplayWorld.h"

#include "LevelHolder.h"

const vec2<float> UISize( 0.16f, 0.1f);

const vec2<float> RogueLevelUIPosition( 0.0f, 0.9f);

const vec2<float> HealthUIPosition( 0.21f, 0.9f);

const vec2<float> StrengthUIPosition( 0.42f, 0.9f);

const vec2<float> GoldUIPosition( 0.63f, 0.9f);

const vec2<float> ArmorUIPosition( 0.84f, 0.9f);

GameplayWorld::GameplayWorld()
{
	this->Levels = std::make_unique<LevelHolder>(this);

	this->RoguePtr = std::make_unique<Rogue>(this->Levels->getCurrentLevel(), this->Levels->getSpawnPosition());

	this->RogueLevelUI = std::make_unique<AtributeLabel>("Level", this->RoguePtr->getCurrentLevel(), RogueLevelUIPosition, UISize);

	this->HealthUIPtr = std::make_unique<HealthUI>(this->RoguePtr->getCurrentHealth(), this->RoguePtr->getMaxHealth(), HealthUIPosition, UISize);

	this->StrengthUI = std::make_unique<AtributeLabel>("Strength", this->RoguePtr->getCurrentStrength(), StrengthUIPosition, UISize);

	this->GoldUI = std::make_unique<AtributeLabel>("Gold", this->RoguePtr->getGoldValue(), GoldUIPosition, UISize);

	this->ArmorUI = std::make_unique<AtributeLabel>("Armor", this->RoguePtr->getCurrentArmor(), ArmorUIPosition, UISize);
}

GameplayWorld::~GameplayWorld()
{
}

Rogue* GameplayWorld::getRoguePtr()
{
	return this->RoguePtr.get();
}
