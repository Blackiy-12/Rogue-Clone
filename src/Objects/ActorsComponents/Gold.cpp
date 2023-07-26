#include "Gold.h"

Gold::Gold() : GoldValue(0)
{
}

Gold::Gold(int Value) : GoldValue(Value)
{
}

Gold::~Gold()
{
}

void Gold::addGold(int Value)
{
    this->GoldValue += Value;
}

int Gold::getGoldValue()
{
    return this->GoldValue;
}
