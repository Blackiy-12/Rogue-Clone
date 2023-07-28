#include "Level.h"

#include "../Objects/Monster/Monster.h"
#include "LevelHolder.h"
#include "../Objects/Rogue.h"

Level::Level(LevelHolder* Holder) : SpawnLocation(0,0), Holder(Holder)
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

    auto CurrentMonster = this->MonstersOnLevel.begin();
    while (CurrentMonster != this->MonstersOnLevel.end())
    {
        if (CurrentMonster->get()->getLevelPosition() == LevelPosition)
            return ObjectClass::ACTOR;

        CurrentMonster++;
    }

    if (this->Holder->getRogue()->getLevelPosition() == LevelPosition)
        return ObjectClass::ACTOR;

    return ObjectClass::NONE;
}

Actor* Level::getActor(vec2<int> ActorPosition)
{
    if (this->Holder->getRogue()->getLevelPosition() == ActorPosition)
        return this->Holder->getRogue();

    auto CurrentMonster = this->MonstersOnLevel.begin();
    while (CurrentMonster != this->MonstersOnLevel.end())
    {
        if (CurrentMonster->get()->getLevelPosition() == ActorPosition)
            return CurrentMonster->get();

        CurrentMonster++;
    }

    return nullptr;
}
