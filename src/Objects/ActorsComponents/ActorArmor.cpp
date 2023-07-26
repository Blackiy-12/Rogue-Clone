#include "ActorArmor.h"

ActorArmor::ActorArmor() : ArmorClass(1)
{
}

ActorArmor::ActorArmor(int ArmorClass) : ArmorClass(ArmorClass)
{
}

ActorArmor::~ActorArmor()
{
}

void ActorArmor::setNewArmor(int NewArmorClass)
{
    NewArmorClass < 0 ? this->ArmorClass = 0 : this->ArmorClass = NewArmorClass;
}

int ActorArmor::getArmorClass()
{
    return this->ArmorClass;
}
