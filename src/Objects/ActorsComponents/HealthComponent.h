#pragma once
class HealthComponent
{
public:
	HealthComponent(int CountOfDice, int SidesOfDice);

	HealthComponent();

	~HealthComponent();

	void increaseMaxHP();

	void decreaseHP(int NumberToDeacrease);

	int getCurrentHP();

	int getMaxHP();

	bool isCurrentHealthIsZero();

private:
	int CurrentHP;

	int MaxHP;
};

