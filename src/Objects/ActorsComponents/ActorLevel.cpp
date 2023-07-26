#include "ActorLevel.h"

ActorLevel::ActorLevel() : CurrentLevel(1), Expirence(0)
{
}

ActorLevel::ActorLevel(int Level, int Exp) : CurrentLevel(Level), Expirence(Exp)
{
}

ActorLevel::~ActorLevel()
{
}

int ActorLevel::getCurrentLevel()
{
    return this->CurrentLevel;
}
