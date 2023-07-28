#include "AtackComponent.h"

#include "../../Random/Randomizer.h"

AtackComponent::AtackComponent(int DamageCountOfDice, int DamageSidesOfDice) : DamageCountOfDice(DamageCountOfDice), DamageSidesOfDice(DamageSidesOfDice)
{
}

AtackComponent::~AtackComponent()
{
}

void AtackComponent::setNewDamage(int DamageCountOfDice, int DamageSidesOfDice)
{
    this->DamageCountOfDice = DamageCountOfDice;
    this->DamageSidesOfDice = DamageSidesOfDice;
}

int AtackComponent::trowDamage()
{
    return Randomizer::getRandomizerPointer()->throwDice(this->DamageCountOfDice, this->DamageSidesOfDice);
}
