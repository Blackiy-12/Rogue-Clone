#include "Level.h"

#include "../Objects/Monster/Monster.h"

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

ObjectClass Level::getObjectsClass(vec2<int> LevelPosition)
{
    auto CurretRoom = this->Rooms.begin();
    while (CurretRoom != this->Rooms.end())
    {
        if (CurretRoom->get()->isOnWall(LevelPosition))
            return ObjectClass::ENVIROMENT;

        CurretRoom++;
    }

    return ObjectClass::NONE;
}
