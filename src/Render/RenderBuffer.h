#pragma once

#include <list>
#include "../Object/GraphicRepresentaion/GraphicOfObject.h"

class RenderBuffer
{
public:
	RenderBuffer(RenderBuffer& other) = delete;

	void operator=(const RenderBuffer&) = delete;

	static RenderBuffer* getRenderBuffer();

	int getNumberOfPriorite();

	void addRenderPriorite();

	void addObjectToRender(GraphicOfObject* Object, int Priorite);

	void removeObjectFromRender(GraphicOfObject* Object);

	void removeObjectFromRender(GraphicOfObject* Object, int Priorite);

private:
	static RenderBuffer* RenderBufferPtr;

	std::list<std::list<GraphicOfObject*>> RenderPriorities;

private:
	RenderBuffer();

	~RenderBuffer();

	friend class Render;
};

