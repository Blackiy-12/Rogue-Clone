#include "TextureHolder.h"

TextureHolder* TextureHolder::TextureHolderPtr = nullptr;

TextureHolder::TextureHolder()
{
}

TextureHolder::~TextureHolder()
{
}

TextureHolder* TextureHolder::getTextureHolder()
{
    if (TextureHolder::TextureHolderPtr == nullptr)
        TextureHolder::TextureHolderPtr = new TextureHolder;

    return TextureHolder::TextureHolderPtr;
}

void TextureHolder::addTexture(std::string TextureName, std::shared_ptr<Texture> TexurePtr)
{
}
