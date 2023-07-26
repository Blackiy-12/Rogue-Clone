#pragma once

class ActorStrength
{
public:
	ActorStrength();

	ActorStrength(int StrengthValue);

	~ActorStrength();

	void increaseStrength();

	int getStrength();

private:
	int Strength;
};

