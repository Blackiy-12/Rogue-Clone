#pragma once

#include "Texture.h"
#include <memory>
#include <string>

class TextureCreator
{
public:
	static std::shared_ptr<Texture> createTexure(const char* TextureName, int RotationAngle);

	static std::shared_ptr<Texture> createLabelTexture(std::string LabelText);

};

