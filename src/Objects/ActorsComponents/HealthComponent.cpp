#include "HealthComponent.h"
#include "../../Random/Randomizer.h"

const int START_HP = 12;

HealthComponent::HealthComponent(int CountOfDice, int SidesOfDice)
{
	this->MaxHP = Randomizer::getRandomizerPointer()->throwDice(CountOfDice, SidesOfDice);
	this->CurrentHP = this->MaxHP;
}

HealthComponent::HealthComponent()
{
	this->MaxHP = START_HP;
	this->CurrentHP = this->MaxHP;
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::increaseMaxHP()
{
	int IncreasedAmount = Randomizer::getRandomizerPointer()->random(3, 10);

	this->MaxHP += IncreasedAmount;
	this->CurrentHP += IncreasedAmount;
}

void HealthComponent::decreaseHP(int NumberToDeacrease)
{
	this->CurrentHP -= NumberToDeacrease;

	if (this->CurrentHP < 0)
		this->CurrentHP = 0;
}

bool HealthComponent::isCurrentHealthIsZero()
{
	if (this->CurrentHP == 0)
		return true;

	return false;
}
