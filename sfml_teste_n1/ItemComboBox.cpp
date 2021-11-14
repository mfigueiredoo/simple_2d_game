#include "ItemComboBox.h"

sf::Vector2f ItemComboBox::getTextCenterAlignmentPosition(sf::RectangleShape rect, sf::Text txtComponent) {
	sf::Vector2f rectSize = sf::Vector2f(rect.getGlobalBounds().width, rect.getGlobalBounds().height);
	sf::Vector2f rectPos = sf::Vector2f(rect.getGlobalBounds().left, rect.getGlobalBounds().top);

	sf::Vector2f textSize = sf::Vector2f(txtComponent.getGlobalBounds().width, txtComponent.getGlobalBounds().height);

	sf::Vector2f textPos;

	float x = rectPos.x + (rectSize.x / 2);
	float y = rectPos.y + (rectSize.y / 2);

	textPos.x = x - (textSize.x / 2);
	textPos.y = y - (textSize.y / 2);

	return sf::Vector2f(textPos.x, textPos.y);
}

ItemComboBox::ItemComboBox()
{
	this->initVariables();
}

ItemComboBox::ItemComboBox(sf::Font* font, std::string text, int index, sf::Vector2f size, sf::Vector2f pos, float charSize)
{
	this->initVariables();
	this->text = text;
	this->index = index;

	this->initialSize = size;
	this->initialPosition = pos;
	

	this->charSize = charSize;
	this->font = font;

	this->background.setSize(this->initialSize);
	this->background.setPosition(this->initialPosition);

	this->textComponent.setFont(*this->font);
	this->textComponent.setString(this->text);
	this->textComponent.setCharacterSize(this->charSize);

	if (this->index == 0)
	{
		this->background.setFillColor(this->bgSelectedColor);
		this->textComponent.setFillColor(this->txtSelectedColor);
	}
	else {
		this->background.setFillColor(this->bgDefaultColor);
		this->textComponent.setFillColor(this->txtDefaultColor);
	}

	this->currentSize = this->initialSize;
	this->currentPosition = this->initialPosition;

	this->textComponent.setPosition(getTextCenterAlignmentPosition(this->background, this->textComponent));

}

ItemComboBox::~ItemComboBox()
{
}

void ItemComboBox::onMouseOver(bool isMouseEntered)
{
	this->isMouseOver = isMouseEntered;
}

int ItemComboBox::onClick(bool isMouseEntered)
{

	this->isSelected = isMouseEntered;
	if (this->isSelected) { return this->index; }

	return -1;
}

void ItemComboBox::initVariables()
{
	this->index = 0;
	this->text = std::string("ComboBox Item");

	this->charSize = 24.f;
	this->font = nullptr;

	this->initialSize = sf::Vector2f();
	this->currentSize = sf::Vector2f();

	this->initialPosition = sf::Vector2f();
	this->currentPosition = sf::Vector2f();

	this->background = sf::RectangleShape();
	this->textComponent = sf::Text();

	this->isVisible = true;
	this->isSelected = false;
}

void ItemComboBox::update(bool isSelected)
{
	this->isSelected = isSelected;
	if (this->isSelected) {
		this->background.setFillColor(this->bgSelectedColor);
		this->textComponent.setFillColor(this->txtSelectedColor);
		this->isSelected = true;
	}
	else { this->isSelected = false; }

	if (this->isMouseOver) {
		this->background.setFillColor(this->bgMouseOverColor);
		this->textComponent.setFillColor(this->txtMouseOverColor);
	}

	if (!this->isMouseOver && !this->isSelected) {
		this->background.setFillColor(this->bgDefaultColor);
		this->textComponent.setFillColor(this->txtDefaultColor);
	}

	this->background.setSize(this->currentSize);
	this->background.setPosition(this->currentPosition);
	this->textComponent.setPosition(getTextCenterAlignmentPosition(this->background, this->textComponent));

}

void ItemComboBox::render(sf::RenderWindow* win)
{
	if (!this->isVisible) { return; }
	win->draw(this->background);
	win->draw(this->textComponent);
}
