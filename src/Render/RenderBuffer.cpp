#include "RenderBuffer.h"

RenderBuffer* RenderBuffer::RenderBufferPtr = nullptr;

RenderBuffer* RenderBuffer::getRenderBuffer()
{
    if (RenderBuffer::RenderBufferPtr == nullptr)
        RenderBuffer::RenderBufferPtr = new RenderBuffer;

    return RenderBuffer::RenderBufferPtr;
}

int RenderBuffer::getNumberOfPriorite()
{
    return this->RenderPriorities.size();
}

void RenderBuffer::addRenderPriorite()
{
    this->RenderPriorities.push_back(std::list<GraphicOfObject*>());
}

void RenderBuffer::addObjectToRender(GraphicOfObject* Object, int Priorite)
{
    auto CurrentPriorite = this->RenderPriorities.begin();
    int RenderIndex = 0;

    while (RenderIndex != Priorite)
    {
        CurrentPriorite++;
        RenderIndex++;
    }

    CurrentPriorite->push_back(Object);
}

void RenderBuffer::removeObjectFromRender(GraphicOfObject* Object)
{
    for (auto CurrentPriorite = this->RenderPriorities.begin(); CurrentPriorite != this->RenderPriorities.end(); CurrentPriorite++)
    {
        CurrentPriorite->remove(Object);
    }
}

void RenderBuffer::removeObjectFromRender(GraphicOfObject* Object, int Priorite)
{
    auto CurrentPriorite = this->RenderPriorities.begin();
    int RenderIndex = 0;

    while (RenderIndex != Priorite)
    {
        CurrentPriorite++;
        RenderIndex++;
    }

    CurrentPriorite->remove(Object);
}

RenderBuffer::RenderBuffer()
{
}

RenderBuffer::~RenderBuffer()
{
}
