#pragma once

#include "../../vec.h"
#include "../../Texture/Texture.h"
#include <memory>
#include <string>


struct RenderInfo
{
	
public:
	SDL_Rect Placement;

	SDL_Texture* Texture;

public:
	RenderInfo(vec2<float> TopLeftPosition, vec2<float> Size, SDL_Texture* Texture);

	void applyWindwoSize(vec2<int> WindowSize);

private:
	vec2<float> TopLeftPosition;

	vec2<float> Size;
};

class GraphicOfObject
{
public:
	GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string TextureName, int RotationAngle, int RenderPrioritie);

	GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string LabelText, int RenderPrioritie);

	~GraphicOfObject() {}

	vec2<float> getSize();

	vec2<float> getPosition();

	RenderInfo getRenderInfo();

private:
	vec2<float> TopLeftPosition;
	
	vec2<float> Size;

	std::shared_ptr<Texture> TexturePtr;
};

