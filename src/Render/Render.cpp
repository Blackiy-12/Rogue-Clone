#include "Render.h"

#include <string>

Render* Render::RenderPtr = nullptr;

std::string WindowTitle = "Rogue Clone";

Render* Render::getRender()
{
	if (Render::RenderPtr == nullptr)
		Render::RenderPtr = new Render();

	return Render::RenderPtr;
}

Render::Render()
{
	this->WindowPtr = SDL_CreateWindow(WindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);

	this->RendererPtr = SDL_CreateRenderer(this->WindowPtr, -1, SDL_RENDERER_ACCELERATED );

}

Render::~Render()
{
}
