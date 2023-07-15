#pragma once

#include "GraphicRepresentaion/GraphicOfObject.h"
#include <memory>

class Object
{
public:
	Object() : Graphic(nullptr){}

	virtual ~Object() {};

protected:
	std::unique_ptr<GraphicOfObject> Graphic;
};

