#include "Level.h"

Level::Level() : SpawnLocation(0,0)
{
}

Level::~Level()
{
}

void Level::generateLevel()
{
}

vec2<int> Level::getSpawnLocation()
{
    return this->SpawnLocation;
}
