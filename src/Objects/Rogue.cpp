#include "Rogue.h"

#include "../Gameplay/Level.h"
#include "../Texture/TextueNames.h"

Rogue::Rogue(GameplayWorld* World, vec2<int> LevelPosition) : Actor(World, LevelPosition), RogueLevel(), GoldValue()
{
	this->Graphic = std::make_unique<GraphicOfObject>(CellSize, vec2<float>{ 0.0f, 0.0f }, TextureNames[TEXURE_NAME_INDEX::DOOR], 0, 2);

	this->updatePosition(this->LevelPosition);

	this->Health = std::make_unique<HealthComponent>();
}

Rogue::~Rogue()
{
}

void Rogue::receiveMessage(InputMessage Message)
{
	if (Message.Type == InputType::KEYBOARD)
	{
		switch (Message.KeyCode)
		{
		case SDLK_w:
			this->move(vec2<int>(0, -1));
			Input::getInput()->stopGettingInput();
			break;

		case SDLK_d:
			this->move(vec2<int>(1, 0));
			Input::getInput()->stopGettingInput();
			break;

		case SDLK_a:
			this->move(vec2<int>(-1, 0));
			Input::getInput()->stopGettingInput();
			break;

		case SDLK_s:
			this->move(vec2<int>(0, 1));
			Input::getInput()->stopGettingInput();
			break;

		default:
			break;
		}
	}
}

int Rogue::getCurrentHealth()
{
	return this->Health->getCurrentHP();
}

int Rogue::getMaxHealth()
{
	return this->Health->getMaxHP();
}

int Rogue::getCurrentLevel()
{
	return this->RogueLevel.getCurrentLevel();
}

int Rogue::getGoldValue()
{
	return this->GoldValue.getGoldValue();
}

void Rogue::move(vec2<int> VectorOfMovment)
{
	auto PositbleNewPosition = this->LevelPosition + VectorOfMovment;

	this->updatePosition(PositbleNewPosition);
}
