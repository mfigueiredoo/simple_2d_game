#include "Button.h"


Button::Button()
{
	this->initVariables();
}

Button::Button(sf::Font* font, std::string text, std::string name, sf::Vector2f size, sf::Vector2f pos, float charSize, sf::Vector2f padding)
{
	this->initVariables();

	this->text = text;
	this->charSize = charSize;
	this->padding = padding;
	this->name = name;

	this->textComponent.setFont(*font);
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setString(this->text);
	this->textComponent.setFillColor(this->txtDefaultColor);
	this->textComponent.setPosition(pos);

	this->size = size;
	this->minSize = sf::Vector2f(textComponent.getGlobalBounds().width, textComponent.getGlobalBounds().height);
	
	if (this->size.x >= this->minSize.x) { this->currentSize.x = this->size.x; }
	else { this->currentSize.x = this->minSize.x; }

	this->currentSize.y = this->minSize.y;

	this->background.setSize(this->currentSize);

	this->background.setPosition(pos);
	this->background.setFillColor(this->bgDefaultColor);
	this->background.setOutlineThickness(2.f);
	this->background.setOutlineColor(this->borderDefaultColor);

	this->textCenter();
}

Button::~Button()
{
}

void Button::initVariables()
{

	this->padding = sf::Vector2f();
	this->minSize = sf::Vector2f();
	this->size = sf::Vector2f();
	this->currentSize = sf::Vector2f();
	this->charSize = 0.f;
	this->text = std::string();
	this->text = "BUTTON";
	this->textComponent = sf::Text();
	this->textPosition = sf::Vector2f();
	this->background = sf::RectangleShape();
	this->name = "defaultName";

	this->isVisible = true;
	this->isMouseOver = false;

}

void Button::textCenter()
{
	this->background.setSize(sf::Vector2f(this->currentSize.x + (this->padding.x * 2), this->currentSize.y + (this->padding.y * 2)));

	this->textPosition.x = (((this->background.getGlobalBounds().width / 2) + this->background.getGlobalBounds().left) - (this->textComponent.getGlobalBounds().width / 2));
	this->textPosition.y = (((this->background.getGlobalBounds().height / 2) + this->background.getGlobalBounds().top) - (this->textComponent.getGlobalBounds().height / 2));

	this->textComponent.setPosition(this->textPosition);
}

void Button::onMouseOver(bool isMouseEntered)
{
	this->isMouseOver = isMouseEntered;
}

void Button::onClick(bool isMouseEntered)
{
	if (!isMouseEntered) { return; }
	if (&this->click == nullptr) { return; }

	this->click();
}


void Button::update()
{
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setString(this->text);
	this->textCenter();

	if (this->isMouseOver) {

		this->background.setFillColor(this->bgMouseOverColor);
		this->textComponent.setFillColor(this->txtMouseOverColor);
		this->background.setOutlineColor(this->borderMouseOverColor);
	}
	else if (!this->isMouseOver) {

		this->background.setFillColor(this->bgDefaultColor);
		this->textComponent.setFillColor(this->txtDefaultColor);
		this->background.setOutlineColor(this->borderDefaultColor);
	}

}

void Button::render(sf::RenderWindow* win)
{
	if (!this->isVisible) { return; }
	win->draw(this->background);
	win->draw(this->textComponent);
}
