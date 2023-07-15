#include "SelectedButton.h"

#include "../Render/RenderBuffer.h"
#include "../Texture/TextueNames.h"

SelectedButton::SelectedButton(vec2<float> Position, vec2<float> Size) : Object()
{
	this->Graphic = std::make_unique<GraphicOfObject>(Size, Position, TextureNames[TEXURE_NAME_INDEX::SELECTED_BUTTON], 0, 1);
}

SelectedButton::~SelectedButton()
{
}

void SelectedButton::setNewPositionAndSize(vec2<float> Position, vec2<float> Size)
{
	this->Graphic->setNewPosition(Position);

	this->Graphic->setNewSize(Size);
}
