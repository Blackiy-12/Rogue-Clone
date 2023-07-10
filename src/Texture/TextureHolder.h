#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include "Texture.h"

class TextureHolder
{
public:
	TextureHolder(TextureHolder& other) = delete;

	void operator=(const TextureHolder&) = delete;

	static TextureHolder* getTextureHolder();

	void addTexture(std::string TextureName, std::shared_ptr<Texture> TexurePtr);

private:
	static TextureHolder* TextureHolderPtr;

	std::unordered_map<std::string, std::shared_ptr<Texture>> Textures;

private:
	TextureHolder();

	~TextureHolder();
};

