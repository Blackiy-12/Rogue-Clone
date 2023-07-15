#pragma once

#include "../Object/Object.h"
#include "../Objects/Button.h"
#include "../Input/InputReceiver.h"
#include "SelectedButton.h"
#include <list>
#include <memory>

enum class ButtonType
{
	NONE,
	PLAY,
	EXIT
};

class ButtonTable : public InputReceiver
{
public:
	ButtonTable(vec2<float> TableCoordinate, vec2<float> Size);

	~ButtonTable();

	void addButton(std::string ButtonText, ButtonType Type);

	void receiveMessage(InputMessage Message) override;

private:
	vec2<float> TopLeftPosition;

	vec2<float> Size;

	std::list<std::unique_ptr<Button>> Buttons;

	std::unique_ptr<SelectedButton> Selector;

	int ButtonSelectedIndex;

private:
	void updateButtonsPosition();

	void updateSelectedButtonPosition();

	void moveUpSelector();

	void moveDownSelector();

	void pressSelectedButton();
};

