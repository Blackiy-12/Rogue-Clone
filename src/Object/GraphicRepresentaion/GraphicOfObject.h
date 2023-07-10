#pragma once

#include "../../vec.h"
#include "../../Texture/Texture.h"
#include <memory>
#include <string>

class GraphicOfObject
{
public:
	GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string TextureName, int RotationAngle);

	GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string LabelText);

	~GraphicOfObject() {}

private:
	vec2<float> BufferCoordinate;
	
	vec2<float> Size;

	std::shared_ptr<Texture> TexturePtr;
};

