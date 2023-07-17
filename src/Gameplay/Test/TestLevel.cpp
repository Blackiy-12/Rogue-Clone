#include "TestLevel.h"

TestLevel::TestLevel()
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
}
