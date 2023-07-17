#include "TextureCreator.h"

#include "TextureHolder.h"
#include "../Render/Render.h"

std::shared_ptr<Texture> TextureCreator::createTexure(const char* TextureName, int RotationAngle)
{
    if (RotationAngle == 0)
        return TextureHolder::getTextureHolder()->getTexture(TextureName);;

    auto Original = TextureHolder::getTextureHolder()->getTexture(TextureName);

    SDL_Texture* Modifire = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

    SDL_SetRenderTarget(Render::getRender()->getRenderer(), Modifire);

    SDL_RenderCopyEx(Render::getRender()->getRenderer(), Original->getTexture(), NULL, NULL, RotationAngle, NULL, SDL_FLIP_NONE);

    SDL_SetRenderTarget(Render::getRender()->getRenderer(), NULL);

    return std::make_shared<Texture>(Modifire);
}

std::shared_ptr<Texture> TextureCreator::createLabelTexture(std::string LabelText)
{
    SDL_Surface* Text = TTF_RenderText_Solid(TextureHolder::getTextureHolder()->getGameFont(), LabelText.c_str(), SDL_Color{0xff, 0xff, 0xff});

    SDL_Texture* TextTeture = SDL_CreateTextureFromSurface(Render::getRender()->getRenderer(), Text);

    SDL_FreeSurface(Text);

    return std::make_shared<Texture>(TextTeture);
}
