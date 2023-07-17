#include "Randomizer.h"

Randomizer* Randomizer::getRandomizerPointer()
{
    return nullptr;
}

int Randomizer::random(int Min, int Max)
{
    std::uniform_int_distribution<int>  Range(Min, Max);

    return Range(this->RandomDevice);
}

int Randomizer::throwDice(int CountOfDice, int SidesOfDice)
{
    std::uniform_int_distribution<int>  Range(1, SidesOfDice);

    int Result = 0;

    for (int i = 0; i < CountOfDice; i++)
        Result += Range(this->RandomDevice);

    return Result;
}

Randomizer::Randomizer()
{
}

Randomizer::~Randomizer()
{
}
