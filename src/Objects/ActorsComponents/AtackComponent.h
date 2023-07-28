#pragma once

class AtackComponent
{
public:
	AtackComponent(int DamageCountOfDice, int DamageSidesOfDice);

	~AtackComponent();

	void setNewDamage(int DamageCountOfDice, int DamageSidesOfDice);

	int trowDamage();

private:
	int DamageCountOfDice;
	
	int DamageSidesOfDice;
};

