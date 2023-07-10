#pragma once

#include <SDL.h>

class Render
{
public:

	Render(Render& other) = delete;

	void operator=(const Render&) = delete;

	static Render* getRender();

private:
	static Render* RenderPtr;

	SDL_Window* WindowPtr;

	SDL_Renderer* RendererPtr;

private:
	Render();

	~Render();
};

