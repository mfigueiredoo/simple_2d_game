#include "ComboBox.h"

sf::Vector2f ComboBox::getTextCenterAlignmentPosition(sf::RectangleShape rect, sf::Text txtComponent) {
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

void ComboBox::sizeAjustment() {
	this->minSize = sf::Vector2f(this->textComponent.getGlobalBounds().width, textComponent.getGlobalBounds().height);

	if (this->currentSize.x >= this->minSize.x) { this->currentSize.x = this->currentSize.x; }
	else { this->currentSize.x = this->minSize.x; }

	if (this->currentSize.y >= this->minSize.y) { this->currentSize.y = this->currentSize.y; }
	else { this->currentSize.y = this->minSize.y; }

	this->background.setSize(sf::Vector2f(this->currentSize.x + (this->padding.x * 2), this->currentSize.y + (this->padding.y * 2)));

	this->dropButton.setSize(sf::Vector2f(this->background.getGlobalBounds().height, this->background.getGlobalBounds().height));
	this->dropButton.setPosition(sf::Vector2f((this->background.getGlobalBounds().left + this->background.getGlobalBounds().width) - this->dropButton.getGlobalBounds().width, (this->background.getGlobalBounds().top + this->background.getGlobalBounds().height) - this->dropButton.getGlobalBounds().height));
	this->textComponent.setPosition(getTextCenterAlignmentPosition(this->background, this->textComponent));
	this->dropButtonArrowComponent.setPosition(getTextCenterAlignmentPosition(this->dropButton, this->dropButtonArrowComponent));
}


ComboBox::ComboBox()
{
	this->initVariables();
}

ComboBox::ComboBox(sf::Font* font, sf::Vector2f size, sf::Vector2f pos, float charSize, sf::Vector2f padding)
{
	this->initVariables();
	this->font = font;
	this->initialSize = size;
	this->initialPosition = pos;
	this->charSize = charSize;
	this->padding = padding;

	
	this->background.setPosition(this->initialPosition);
	this->background.setFillColor(this->bgDefaultColor);
	this->background.setOutlineThickness(2.f);
	this->background.setOutlineColor(this->borderDefaultColor);

	this->textComponent.setFont(*this->font);
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setFillColor(this->txtDefaultColor);

	if (this->items.size() > 0) { this->textComponent.setString(this->items[selectedItemIndex].text); }
	else { this->textComponent.setString(std::string("ComboBox Item[0]")); }
	
	
	this->dropButton.setFillColor(this->bgDropButtonDefaultColor);

	this->dropButtonArrowComponent.setFont(*this->font);
	this->dropButtonArrowComponent.setCharacterSize(this->charSize);
	this->dropButtonArrowComponent.setFillColor(this->txtDropButtonDefaultColor);
	this->dropButtonArrowComponent.setString(this->dropButtonArrow);
	


	this->currentSize = this->initialSize;
	
	this->sizeAjustment();

}

ComboBox::~ComboBox()
{
}

void ComboBox::initVariables()
{
	this->font = nullptr;
	this->charSize = 24.f;

	this->initialSize = sf::Vector2f();
	this->initialPosition = sf::Vector2f();

	this->items = std::vector<ItemComboBox>();
	this->selectedItemIndex = 0;

	this->background = sf::RectangleShape();
	this->textComponent = sf::Text();
	this->dropButton = sf::RectangleShape();

	this->dropButtonArrow = 'V';
	this->dropButtonArrowComponent = sf::Text();

	this->isVisible = true;
	this->isActive = false;

	this->background.setFillColor(this->bgDefaultColor);

	this->textComponent.setFillColor(this->txtDefaultColor);

}

void ComboBox::onMouseOver(bool isMouseEntered)
{
	if (isMouseEntered) { this->isMouseOver = true; }
	else { this->isMouseOver = false; }
}

void ComboBox::onClick(bool isMouseEntered)
{
	if (isMouseEntered) { this->isActive = true; }
	else { this->isActive = false; }
}

void ComboBox::addItem(ItemComboBox item)
{
	this->items.push_back(item);
}

void ComboBox::update()
{
	if (this->items.size() > 0) { this->textComponent.setString(this->items[selectedItemIndex].text); }
	else { this->textComponent.setString(std::string("ComboBox Item[0]")); }

	this->sizeAjustment();

	// Update Items
	for (size_t i = 0; i < this->items.size(); i++) {

		if (this->selectedItemIndex == this->items[i].index) {
			this->items[i].isSelected = true;
		}
		else { this->items[i].isSelected = false; }

		this->items[i].currentSize = this->background.getSize();
		this->items[i].currentPosition = sf::Vector2f(this->background.getPosition().x, this->background.getPosition().y + this->background.getGlobalBounds().height + (i * this->items[i].currentSize.y));

		this->items[i].update(this->items[i].isSelected);
	}
	
	// Update ComboBox Control

	if (this->isMouseOver) {
		this->background.setFillColor(this->bgMouseOverColor);
		this->textComponent.setFillColor(this->txtMouseOverColor);
	}

	if (this->isActive)
	{
		this->background.setFillColor(this->bgActiveColor);
		this->textComponent.setFillColor(this->txtActiveColor);
	}


	if (!this->isMouseOver && !this->isActive) {
		this->background.setFillColor(this->bgDefaultColor);
		this->textComponent.setFillColor(this->txtDefaultColor);
	}

}

void ComboBox::render(sf::RenderWindow* win)
{
	if (!this->isVisible) { return; }

	win->draw(this->background);
	win->draw(this->textComponent);
	win->draw(this->dropButton);
	win->draw(this->dropButtonArrowComponent);

	if (!this->isActive) { return; }

	for (size_t i = 0; i < this->items.size(); i++)
	{
		this->items[i].render(win);
	}

}
