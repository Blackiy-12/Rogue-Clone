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
	//Label
	GraphicOfObject(vec2<float> Size, vec2<float> Position, const char* TextureName, int RotationAngle, int RenderPrioritie);

	//Common object
	GraphicOfObject(vec2<float> Size, vec2<float> Position, std::string LabelText, int RenderPrioritie);

	//Floor
	GraphicOfObject(vec2<float> Size, vec2<float> Position, vec2<int> FloorSize, int RenderPrioritie);

	~GraphicOfObject();

	void setNewPosition(vec2<float> NewPosition);
	
	void setNewSize(vec2<float> NewSize);

	vec2<float> getSize();

	vec2<float> getPosition();

	RenderInfo getRenderInfo();

private:
	vec2<float> TopLeftPosition;
	
	vec2<float> Size;

	std::shared_ptr<Texture> TexturePtr;
};

