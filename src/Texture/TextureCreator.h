#pragma once

#include "Texture.h"
#include <memory>
#include <string>

class TextureCreator
{
public:
	static std::shared_ptr<Texture> createTexure(std::string TextureName, int RotationAngle);

	static std::shared_ptr<Texture> createLabelTexture(std::string LabelText);

};

