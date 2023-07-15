#include "TextureLoader.h"

#include "TextureHolder.h"
#include "TextueNames.h"
#include "../Render/Render.h"
#include <SDL_image.h>

const char UITileFilePath[] = "./res/UI.png";

void TextureLoader::loadUITextures()
{
	IMG_Init(IMG_INIT_PNG);

	SDL_Texture* TextureUI = IMG_LoadTexture(Render::getRender()->getRenderer(), UITileFilePath);

	SDL_Texture* TextureSelectedButton = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureSelectedButton);

	SDL_RenderCopy(Render::getRender()->getRenderer(), TextureUI, NULL, NULL);

	std::shared_ptr<Texture> SelectedButton = std::make_shared<Texture>(TextureSelectedButton);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::SELECTED_BUTTON], SelectedButton);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), NULL);

	SDL_DestroyTexture(TextureUI);

	IMG_Quit();
}
