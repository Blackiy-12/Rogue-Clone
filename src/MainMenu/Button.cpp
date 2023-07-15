#include "Button.h"

Button::Button(std::string ButtonText, vec2<float> Position, vec2<float> Size) : Label(ButtonText)
{
	this->Graphic = std::make_unique<GraphicOfObject>(Size, Position, ButtonText, 0);
}

Button::~Button()
{
}

vec2<float> Button::getPosition()
{
	return this->Graphic->getPosition();
}

vec2<float> Button::getSize()
{
	return this->Graphic->getSize();
}

void Button::setNewPositionAndSize(vec2<float> Position, vec2<float> Size)
{
	this->Graphic->setNewPosition(Position);

	this->Graphic->setNewSize(Size);
}
