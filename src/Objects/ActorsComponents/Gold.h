#pragma once

class Gold
{
public:
	Gold();

	Gold(int Value);

	~Gold();

	void addGold(int Value);

	int getGoldValue();

private:
	int GoldValue;
};

