#include "Texture.h"

Texture::Texture(SDL_Texture* TexturePtr)
{
    this->TexturePtr = TexturePtr;
}

Texture::~Texture()
{
    SDL_DestroyTexture(this->TexturePtr);
}

SDL_Texture* Texture::getTexture()
{
    return this->TexturePtr;
}
