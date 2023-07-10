#include "GraphicOfObject.h"

#include "../../Texture/TextureCreator.h"

GraphicOfObject::GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string TextureName, int RotationAngle) : Size(Size), BufferCoordinate(Position)
{
	this->TexturePtr = TextureCreator::createTexure(TextureName, RotationAngle);
}

GraphicOfObject::GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string LabelText) : Size(Size), BufferCoordinate(Position)
{

}
