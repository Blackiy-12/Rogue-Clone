#include "Label.h"

#include "../Render/RenderBuffer.h"

Label::Label(std::string LabelText, vec2<float> Position, vec2<float> Size)
{
	this->Graphic = std::make_unique<GraphicOfObject>(Size, Position, LabelText, 0);
	this->LabelText = LabelText;

	RenderBuffer::getRenderBuffer()->addObjectToRender(this->Graphic.get(), 0);
}

Label::~Label()
{
}
