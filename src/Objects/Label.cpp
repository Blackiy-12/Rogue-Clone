#include "Label.h"

#include "../Render/RenderBuffer.h"

Label::Label(std::string LabelText, vec2<float> Position, vec2<float> Size)
{
	this->Graphic = std::make_unique<GraphicOfObject>(Size, Position, LabelText, 0);
	this->LabelText = LabelText;
}

Label::~Label()
{
}

void Label::updateText(std::string NewText)
{
	if (this->LabelText == NewText)
		return;

	this->LabelText = NewText;
	this->Graphic->setNewTextTexture(this->LabelText);
}

Label::Label(std::string LabelText)
{
	this->LabelText = LabelText;
}
