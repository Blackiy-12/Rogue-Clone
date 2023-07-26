#include "TextureLoader.h"

#include "TextureHolder.h"
#include "TextueNames.h"
#include "../Render/Render.h"
#include <SDL_image.h>

const char UITileFilePath[] = "./res/UI.png";

const char EnviromentTileFilePath[] = "./res/Enviroment.png";

void loadTexture(SDL_Texture* TileMap, SDL_Rect* TexturePosition, TEXURE_NAME_INDEX TextureName)
{
	SDL_Texture* TexturePtr = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TexturePtr);

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, TexturePosition, NULL);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TextureName], std::make_shared<Texture>(TexturePtr));

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), NULL);
}

void TextureLoader::loadUITextures()
{
	IMG_Init(IMG_INIT_PNG);

	SDL_Texture* TextureUI = IMG_LoadTexture(Render::getRender()->getRenderer(), UITileFilePath);

	loadTexture(TextureUI, NULL, TEXURE_NAME_INDEX::SELECTED_BUTTON);

	SDL_DestroyTexture(TextureUI);

	IMG_Quit();
}

void TextureLoader::loadEnviromentTextures()
{
	IMG_Init(IMG_INIT_PNG);

	SDL_Texture* TileMap = IMG_LoadTexture(Render::getRender()->getRenderer(), EnviromentTileFilePath);

	//Wall
	SDL_Texture* TextureWall = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureWall);

	SDL_Rect WallPosition = {0, 0, 16, 16};

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, &WallPosition, NULL);

	std::shared_ptr<Texture> Wall = std::make_shared<Texture>(TextureWall);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::STRAIGHT_WALL], Wall);

	//Corner
	SDL_Texture* TextureWallCorner = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureWallCorner);

	SDL_Rect WallCornerPosition = { 16, 0, 16, 16 };

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, &WallCornerPosition, NULL);

	std::shared_ptr<Texture> WallCorner = std::make_shared<Texture>(TextureWallCorner);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::CORNER_WALL], WallCorner);

	//Door
	SDL_Texture* TextureDoor = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureDoor);

	SDL_Rect DoorPosition = { 0, 16, 16, 16 };

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, &DoorPosition, NULL);

	std::shared_ptr<Texture> Door = std::make_shared<Texture>(TextureDoor);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::DOOR], Door);

	//Stairs
	SDL_Texture* TextureStairs = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureStairs);

	SDL_Rect StairsPosition = { 16, 16, 16, 16 };

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, &StairsPosition, NULL);

	std::shared_ptr<Texture> Stairs = std::make_shared<Texture>(TextureStairs);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::STAIRS], Stairs);

	//Floor
	SDL_Texture* TextureFloor = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureFloor);

	SDL_Rect FloorPosition = { 32, 0, 16, 16 };

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, &FloorPosition, NULL);

	std::shared_ptr<Texture> Floor = std::make_shared<Texture>(TextureFloor);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::FLOOR], Floor);

	//Tunnel
	SDL_Texture* TextureTunnel = SDL_CreateTexture(Render::getRender()->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);

	SDL_SetRenderTarget(Render::getRender()->getRenderer(), TextureTunnel);

	SDL_Rect TunnelPosition = { 16, 0, 16, 16 };

	SDL_RenderCopy(Render::getRender()->getRenderer(), TileMap, &TunnelPosition, NULL);

	std::shared_ptr<Texture> Tunnel = std::make_shared<Texture>(TextureTunnel);

	TextureHolder::getTextureHolder()->addTexture(TextureNames[TEXURE_NAME_INDEX::TUNNEL], Tunnel);


	SDL_SetRenderTarget(Render::getRender()->getRenderer(), NULL);

	SDL_DestroyTexture(TileMap);

	IMG_Quit();
}
