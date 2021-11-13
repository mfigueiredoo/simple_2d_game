#include "GUI_Controls.h"

Button* GUI_Controls::getButtonByName(std::string buttonName)
{
	for (size_t i = 0; i < this->buttons.size(); i++)
	{
		if (this->buttons[i].name == buttonName)
		{
			return &this->buttons[i];
		}
	}

	return &Button();
}

int GUI_Controls::getButtonsLength()
{
	return (int)this->buttons.size();
}
