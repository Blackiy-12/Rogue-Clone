#pragma once

#include <SDL.h>

class GraphicOfObject;

class Render
{
public:

	Render(Render& other) = delete;

	void operator=(const Render&) = delete;

	static Render* getRender();

	SDL_Renderer* getRenderer();

	void drawRenderBuffer();

	void swapRenderer();

	void clearRenderer();

private:
	static Render* RenderPtr;

	SDL_Window* WindowPtr;

	SDL_Renderer* RendererPtr;

private:
	Render();

	~Render();

	void drawObject(GraphicOfObject* Object);
};

