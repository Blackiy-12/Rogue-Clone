#pragma once

#include <random>

class Randomizer
{
public:
	Randomizer(Randomizer& other) = delete;

	void operator=(const Randomizer&) = delete;

	static Randomizer* getRandomizerPointer();

	int random(int Min, int Max);

	int throwDice(int CountOfDice, int SidesOfDice);

private:
	static Randomizer* RandomizerPtr;

	std::random_device RandomDevice;

private:
	Randomizer();
	
	~Randomizer();
};

