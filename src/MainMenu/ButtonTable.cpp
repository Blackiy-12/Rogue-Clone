#include "ButtonTable.h"


ButtonTable::ButtonTable(vec2<float> TableCoordinate, vec2<float> Size) :
	TopLeftPosition(TableCoordinate), Size(Size)
{
	this->ButtonSelectedIndex = -1;
	this->Selector = std::make_unique<SelectedButton>(vec2<float>(1, 1), vec2<float>(0, 0));
}

ButtonTable::~ButtonTable()
{
}

void ButtonTable::addButton(std::string ButtonText)
{
	if (this->ButtonSelectedIndex == -1)
		this->ButtonSelectedIndex = 0;

	this->Buttons.push_back(std::make_unique<Button>(ButtonText, vec2<float>(0,0), vec2<float>(0, 0)));

	this->updateButtonsPosition();

	this->updateSelectedButtonPosition();
}

void ButtonTable::updateButtonsPosition()
{

	auto CurrentButton = this->Buttons.begin();

	int ButtonIndex = 0;

	vec2<float> ButtonSize(this->Size.x, 0.9f* 0.85f * this->Size.y / this->Buttons.size());

	float BetweenButtons = 0.9f * 0.15f * this->Size.y / this->Buttons.size();

	while (CurrentButton != this->Buttons.end())
	{
		vec2<float>  ButtonPosition(this->TopLeftPosition.x, this->TopLeftPosition.y + this->Size.y * 0.1f + BetweenButtons * ButtonIndex + ButtonSize.y * ButtonIndex);

		CurrentButton->get()->setNewPositionAndSize(ButtonPosition, ButtonSize);

		ButtonIndex++;
		CurrentButton++;
	}
}

void ButtonTable::updateSelectedButtonPosition()
{
	auto SelectedButton = this->Buttons.begin();
	
	int CurrentIndex = 0;

	while (CurrentIndex != this->ButtonSelectedIndex)
	{
		SelectedButton++;
		CurrentIndex++;
	}

	auto ButtonPosition = SelectedButton->get()->getPosition();
	
	auto ButtonSize = SelectedButton->get()->getSize();

	vec2<float> NewPosition (ButtonPosition.x + ButtonSize.x, ButtonPosition.y + ButtonSize.y * 0.4f);

	vec2<float> NewSize(0.1f, ButtonSize.y * 0.5f);

	this->Selector->setNewPositionAndSize(NewPosition, NewSize);
}
