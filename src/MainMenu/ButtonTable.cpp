#include "ButtonTable.h"


ButtonTable::ButtonTable(vec2<float> TableCoordinate, vec2<float> Size) :
	TopLeftPosition(TableCoordinate), ButtonSize(Size)
{
	this->ButtonSelected = -1;
}

ButtonTable::~ButtonTable()
{
}

void ButtonTable::addButton(std::string ButtonText)
{
	if (this->ButtonSelected == -1)
		this->ButtonSelected = 0;

	vec2<float> ButtonPosition( TopLeftPosition.x, TopLeftPosition.x + ButtonSize.y * 0.5f * this->Buttons.size());

	this->Buttons.push_back(std::make_unique<Button>(ButtonText, ButtonPosition, ButtonSize));
}
