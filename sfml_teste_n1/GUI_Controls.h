#pragma once

#include <vector>
#include "Intro.h"
#include "Button.h"
#include "Textbox.h"
#include "ComboBox.h"

#ifndef GUI_CONTROLS_H
#define GUI_CONTROLS_H

class GUI_Controls
{
private:
public:

	Intro intro;
	std::vector<Button> buttons;
	std::vector<Textbox> textboxes;
	std::vector<ComboBox> comboboxes;

	Button* getButtonByName(std::string buttonName);
	int getButtonsLength();

};

#endif


