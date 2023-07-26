#pragma once

class ActorArmor
{
public:
	ActorArmor();

	ActorArmor(int ArmorClass);

	~ActorArmor();

	void setNewArmor(int NewArmorClass);

	int getArmorClass();

private:
	int ArmorClass;
};

