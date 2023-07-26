#pragma once
class ActorLevel
{
public:
	ActorLevel();

	ActorLevel(int Level, int Exp);

	~ActorLevel();

	int getCurrentLevel();

private:
	int CurrentLevel;

	const int MAX_LEVEL = 20;

	int Expirence;
};

