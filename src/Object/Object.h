#pragma once

#include "../vec.h"
#include "GraphicRepresentaion/GraphicOfObject.h"
#include <memory>

class Object
{
public:
	Object() : Graphic(nullptr){}

	virtual ~Object() = 0;

	virtual void render() = 0;

protected:

	std::unique_ptr<GraphicOfObject> Graphic;
};

