#include "TestLevel.h"

#include "../../Objects/Monster/Monster.h"

TestLevel::TestLevel(LevelHolder* Holder) : Level(Holder)
{
	this->generateLevel();
}

TestLevel::~TestLevel()
{
}

void TestLevel::generateLevel()
{
	this->Rooms.push_back(std::make_unique<Room>(vec2<int>(0, 0), LEVEL_SIZE));
	this->Rooms.begin()->get()->setVisible();

	this->SpawnLocation = { 5, 5 };

	this->MonstersOnLevel.push_back(std::make_unique<Monster>(this, vec2<int>(60, 8)));
}
