#pragma once

#include <SDL.h>

class Texture
{
public:
	Texture(SDL_Texture* TexturePtr);

	~Texture();

	SDL_Texture* getTexture();

private:

	SDL_Texture* TexturePtr;
};

