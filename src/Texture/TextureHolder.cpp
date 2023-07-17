#include "TextureHolder.h"

TextureHolder* TextureHolder::TextureHolderPtr = nullptr;

std::string FontPath = "./res/Font.ttf";

TextureHolder::TextureHolder()
{
    TTF_Init();

    this->GameFont = TTF_OpenFont(FontPath.c_str(), 100);
}

TextureHolder::~TextureHolder()
{
    TTF_CloseFont(this->GameFont);

    TTF_Quit();
}

TextureHolder* TextureHolder::getTextureHolder()
{
    if (TextureHolder::TextureHolderPtr == nullptr)
        TextureHolder::TextureHolderPtr = new TextureHolder;

    return TextureHolder::TextureHolderPtr;
}

std::shared_ptr<Texture> TextureHolder::getTexture(const char* TextureName)
{
    return this->Textures.at(TextureName);
}

void TextureHolder::addTexture(const char* TextureName, std::shared_ptr<Texture> TexurePtr)
{
    this->Textures.insert({ TextureName, TexurePtr });
}

TTF_Font* TextureHolder::getGameFont()
{
    return this->GameFont;
}
