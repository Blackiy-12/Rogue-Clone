#include "GraphicOfObject.h"

#include "../../Texture/TextureCreator.h"
#include "../../Render/RenderBuffer.h"

GraphicOfObject::GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string TextureName, int RotationAngle, int RenderPrioritie) : Size(Size), TopLeftPosition(Position)
{
	this->TexturePtr = TextureCreator::createTexure(TextureName, RotationAngle);

	RenderBuffer::getRenderBuffer()->addObjectToRender(this, RenderPrioritie);
}

GraphicOfObject::GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string LabelText, int RenderPrioritie) : Size(Size), TopLeftPosition(Position)
{
	this->TexturePtr = TextureCreator::createLabelTexture(LabelText);
}

vec2<float> GraphicOfObject::getSize()
{
	return this->Size;
}

vec2<float> GraphicOfObject::getPosition()
{
	return this->TopLeftPosition;
}

RenderInfo GraphicOfObject::getRenderInfo()
{
	return RenderInfo(this->TopLeftPosition, this->Size, this->TexturePtr->getTexture());
}

RenderInfo::RenderInfo(vec2<float> TopLeftPosition, vec2<float> Size, SDL_Texture* Texture) : 
	TopLeftPosition(TopLeftPosition), Size(Size), Texture(Texture), Placement()
{
}

void RenderInfo::applyWindwoSize(vec2<int> WindowSize)
{
	this->Placement.x = this->TopLeftPosition.x * WindowSize.x;

	this->Placement.w = this->Size.x * WindowSize.x;
	
	this->Placement.y = this->TopLeftPosition.y * WindowSize.y;
	
	this->Placement.h = this->Size.y * WindowSize.y;
}
