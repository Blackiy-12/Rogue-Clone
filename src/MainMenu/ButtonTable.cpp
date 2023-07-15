#include "ButtonTable.h"

#include "ButtonPlay.h"
#include "ButtonExit.h"
#include "../Input/Input.h"


ButtonTable::ButtonTable(vec2<float> TableCoordinate, vec2<float> Size) :
	TopLeftPosition(TableCoordinate), Size(Size)
{
	this->ButtonSelectedIndex = -1;
	this->Selector = std::make_unique<SelectedButton>(vec2<float>(1, 1), vec2<float>(0, 0));
}

ButtonTable::~ButtonTable()
{
}

void ButtonTable::addButton(std::string ButtonText, ButtonType Type)
{
	if (this->ButtonSelectedIndex == -1)
		this->ButtonSelectedIndex = 0;

	switch (Type)
	{
	case ButtonType::NONE:
		this->Buttons.push_back(std::make_unique<Button>(ButtonText, vec2<float>(0, 0), vec2<float>(0, 0)));
		break;
	case ButtonType::PLAY:
		this->Buttons.push_back(std::make_unique<ButtonPlay>(ButtonText, vec2<float>(0, 0), vec2<float>(0, 0)));
		break;
	case ButtonType::EXIT:
		this->Buttons.push_back(std::make_unique<ButtonExit>(ButtonText, vec2<float>(0, 0), vec2<float>(0, 0)));
		break;
	default:
		break;
	}

	this->updateButtonsPosition();

	this->updateSelectedButtonPosition();
}

void ButtonTable::receiveMessage(InputMessage Message)
{
	if (Message.Type == InputType::KEYBOARD)
	{
		switch (Message.KeyCode)
		{
		case SDLK_UP:
			this->moveUpSelector();
			Input::getInput()->stopGettingInput();
			break;
		case SDLK_DOWN:
			this->moveDownSelector();
			Input::getInput()->stopGettingInput();
			break;
		case SDLK_RETURN:
			this->pressSelectedButton();
			Input::getInput()->stopGettingInput();
			break;
		default:
			break;
		}
	}
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

void ButtonTable::moveUpSelector()
{
	this->ButtonSelectedIndex--;
	
	if (this->ButtonSelectedIndex < 0)
		this->ButtonSelectedIndex = this->Buttons.size() - 1;

	this->updateSelectedButtonPosition();
}

void ButtonTable::moveDownSelector()
{
	this->ButtonSelectedIndex++;
	if (this->ButtonSelectedIndex > this->Buttons.size() - 1)
		this->ButtonSelectedIndex = 0;

	this->updateSelectedButtonPosition();
}

void ButtonTable::pressSelectedButton()
{
	auto CurentButton = this->Buttons.begin();

	int CurrentIndex = 0;

	while (CurrentIndex != this->ButtonSelectedIndex)
	{
		CurentButton++;
		CurrentIndex++;
	}

	CurentButton->get()->pressButton();
}
