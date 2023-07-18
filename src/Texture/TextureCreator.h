#pragma once

#include "Texture.h"
#include <memory>
#include <string>
#include "../vec.h"

class TextureCreator
{
public:
	static std::shared_ptr<Texture> createTexure(const char* TextureName, int RotationAngle);

	static std::shared_ptr<Texture> createLabelTexture(std::string LabelText);

	static std::shared_ptr<Texture> createFloorTexture(vec2<int> FloorSize);

};

