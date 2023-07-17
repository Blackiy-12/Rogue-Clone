#pragma once

#include "../Object/Object.h"
#include "../vec.h"
#include "ActorsComponents/HealthComponent.h"
#include <memory>

class Actor : public Object
{
public:
	Actor();

	~Actor();

private:
	vec2<int> LevelPosition;

	std::unique_ptr<HealthComponent> Health;
};

