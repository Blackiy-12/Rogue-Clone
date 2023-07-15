#include "TextureCreator.h"

#include "TextureHolder.h"
#include "../Render/Render.h"

std::shared_ptr<Texture> TextureCreator::createTexure(const char* TextureName, int RotationAngle)
{
    return TextureHolder::getTextureHolder()->getTexture(TextureName);
}

std::shared_ptr<Texture> TextureCreator::createLabelTexture(std::string LabelText)
{
    SDL_Surface* Text = TTF_RenderText_Solid(TextureHolder::getTextureHolder()->getGameFont(), LabelText.c_str(), SDL_Color{0xff, 0xff, 0xff});

    SDL_Texture* TextTeture = SDL_CreateTextureFromSurface(Render::getRender()->getRenderer(), Text);

    SDL_FreeSurface(Text);

    return std::make_shared<Texture>(TextTeture);
}
