#include "ActorStrength.h"

ActorStrength::ActorStrength() : Strength(1)
{
}

ActorStrength::ActorStrength(int StrengthValue) : Strength(StrengthValue)
{
}

ActorStrength::~ActorStrength()
{
}

void ActorStrength::increaseStrength()
{
    this->Strength++;
}

int ActorStrength::getStrength()
{
    return Strength;
}
