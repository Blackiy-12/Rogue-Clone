#include "Render.h"

#include "RenderBuffer.h"
#include"../Object/GraphicRepresentaion/GraphicOfObject.h"
#include <string>

Render* Render::RenderPtr = nullptr;

std::string WindowTitle = "Rogue Clone";

SDL_Renderer* Render::getRenderer()
{
	return this->RendererPtr;
}

void Render::drawRenderBuffer()
{
	auto Buffer = RenderBuffer::getRenderBuffer();

	auto CurrentPrioritie = Buffer->RenderPriorities.begin();

	while (CurrentPrioritie != Buffer->RenderPriorities.end())
	{
		auto Object = CurrentPrioritie->begin();

		while (Object != CurrentPrioritie->end())
		{
			this->drawObject(*Object);
			Object++;
		}

		CurrentPrioritie++;
	}
}

void Render::swapRenderer()
{
	SDL_RenderPresent(this->RendererPtr);
}

void Render::clearRenderer()
{
	SDL_SetRenderDrawColor(this->RendererPtr, 0x00, 0x00, 0x00, 0xff);

	SDL_RenderClear(this->RendererPtr);
}

Render* Render::getRender()
{
	if (Render::RenderPtr == nullptr)
		Render::RenderPtr = new Render();

	return Render::RenderPtr;
}

Render::Render()
{
	this->WindowPtr = SDL_CreateWindow(WindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_TEXTUREACCESS_TARGET);

	this->RendererPtr = SDL_CreateRenderer(this->WindowPtr, -1, SDL_RENDERER_ACCELERATED );

	RenderBuffer::getRenderBuffer()->addRenderPriorite();

	RenderBuffer::getRenderBuffer()->addRenderPriorite();

	RenderBuffer::getRenderBuffer()->addRenderPriorite();
}

Render::~Render()
{
	SDL_DestroyRenderer(this->RendererPtr);
}

void Render::drawObject(GraphicOfObject* Object)
{
	auto RenderData = Object->getRenderInfo();

	vec2<int> WindowSize(0,0);

	SDL_GetWindowSize(this->WindowPtr, &WindowSize.x, &WindowSize.y);

	RenderData.applyWindwoSize(WindowSize);
	
	SDL_RenderCopy(this->RendererPtr, RenderData.Texture, NULL, &RenderData.Placement);
}
