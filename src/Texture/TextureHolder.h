#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include "Texture.h"
#include <SDL_ttf.h>

class TextureHolder
{
public:
	TextureHolder(TextureHolder& other) = delete;

	void operator=(const TextureHolder&) = delete;

	static TextureHolder* getTextureHolder();

	std::shared_ptr<Texture> getTexture(const char* TextureName);

	void addTexture(const char* TexureName, std::shared_ptr<Texture> TexurePtr);

	TTF_Font* getGameFont();

private:
	static TextureHolder* TextureHolderPtr;

	std::unordered_map<const char*, std::shared_ptr<Texture>> Textures;

	TTF_Font* GameFont;

private:
	TextureHolder();

	~TextureHolder();
};

