#include "Menu.h"

Menu::Menu()
{
	this->initVariables();
}

Menu::Menu(sf::Texture* texture, sf::Font* font, sf::Vector2f initialSize, std::string title, sf::Vector2f intialPosition)
{
	this->initVariables();

	this->texture = texture;
	this->font = font;
	this->initialSize = initialSize;
	this->title = title;
	this->initialPosition = initialPosition;

	this->background.setTexture(this->texture);
	this->background.setSize(this->initialSize);
	this->background.setPosition(this->initialPosition);

	this->textComponent.setFont(*this->font);
	this->textComponent.setString(this->title);
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setPosition(sf::Vector2f(this->initialSize.x * 0.25, this->initialSize.y * 0.4));
	this->textComponent.setFillColor(this->titleColor);
}

Menu::~Menu()
{
}

void Menu::initVariables()
{
	this->controls = GUI_Controls();
	this->background = sf::RectangleShape();
	this->textComponent = sf::Text();
	this->title = std::string();
	this->charSize = 48.f;
	this->titleColor = sf::Color(255, 255, 255, 255);
	this->initialSize = sf::Vector2f();
	this->initialPosition = sf::Vector2f();
	this->font = nullptr;
	this->texture = nullptr;
	this->isVisible = false;
	this->verticalControlsSpacing = 64.f;

}

void Menu::update()
{
	// Buttons
	for (size_t i = 0; i < this->controls.buttons.size(); i++)
	{
		this->controls.buttons[i].update();
	}

	// TextBoxes
	for (size_t i = 0; i < this->controls.textboxes.size(); i++)
	{
		this->controls.textboxes[i].update();
	}

	//ComboBoxes
	for (size_t i = 0; i < this->controls.comboboxes.size(); i++)
	{
		this->controls.comboboxes[i].update();
	}

	//Labels
	for (size_t i = 0; i < this->controls.labels.size(); i++)
	{
		this->controls.labels[i].update();
	}
}

void Menu::render(sf::RenderWindow* win)
{
	

	if (this->isVisible) {
		// Background
		win->draw(this->background);

		//title
		win->draw(this->textComponent);

		// Buttons
		for (size_t i = 0; i < this->controls.buttons.size(); i++)
		{
			this->controls.buttons[i].render(win);
		}

		// TextBoxes
		for (size_t i = 0; i < this->controls.textboxes.size(); i++)
		{
			this->controls.textboxes[i].render(win);
		}

		//ComboBoxes
		for (size_t i = 0; i < this->controls.comboboxes.size(); i++)
		{
			this->controls.comboboxes[i].render(win);
		}

		//Labels
		for (size_t i = 0; i < this->controls.labels.size(); i++)
		{
			this->controls.labels[i].render(win);
		}

	}
}
