#include "Textbox.h"

#define BACKSPACE_KEY = 8;

Textbox::Textbox()
{
	this->initVariables();
}

Textbox::Textbox(sf::Font* font, sf::Vector2f pos, float charSize, sf::Vector2f padding)
{
	this->initVariables();

	this->charSize = charSize;
	this->padding = padding;
	this->initialPosition = pos;

	this->textComponent.setFont(*font);
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setFillColor(this->txtDefaultColor);

	this->textComponent.setString(this->emptyStringWithMaxCharLength);
	this->initialSize = sf::Vector2f(textComponent.getGlobalBounds().width, textComponent.getGlobalBounds().height);
	
	this->textComponent.setString(this->textPlaceHolder);

	this->background.setFillColor(this->bgDefaultColor);
	this->background.setPosition(this->initialPosition);
	this->background.setSize(this->initialSize);

	this->background.setOutlineThickness(0.7f);
	this->background.setOutlineColor(this->txtDefaultColor);

	this->textCenter();

}

Textbox::~Textbox()
{
}

void Textbox::initVariables()
{
	this->maxCharLength = 20;
	this->text = "";

	for (size_t i = 0; i < this->maxCharLength + 8; i++)
	{
		this->emptyStringWithMaxCharLength.push_back('*');
	}

	this->textPlaceHolder = "Username";

	this->textComponent = sf::Text();
	this->background = sf::RectangleShape();

	this->txtDefaultColor = sf::Color(191, 191, 191, 155);
	this->txtMouseOverColor = sf::Color(0, 0, 0, 127);
	this->txtSelectedColor = sf::Color(255, 255, 255, 255);
	this->bgDefaultColor = sf::Color(32, 32, 32, 255);
	this->bgMouseOverColor = sf::Color(255, 255, 255, 127);
	this->bgSelectedColor = sf::Color(0, 0, 0, 255);

	this->isVisible = true;
	this->isSelected = false;
}

void Textbox::textCenter()
{
	this->background.setSize(sf::Vector2f(this->initialSize.x + (this->padding.x * 2), this->initialSize.y + (this->padding.y * 2)));

	sf::Vector2f textPosition;
	textPosition.x = this->padding.x + this->background.getGlobalBounds().left;
	textPosition.y = (((this->background.getGlobalBounds().height / 2) + this->background.getGlobalBounds().top) - (this->textComponent.getGlobalBounds().height / 2));

	this->textComponent.setPosition(textPosition);


}

void Textbox::removeLastChar()
{
	if (!this->text.empty()) {
		if (this->getLastChar() == '_' && this->text.size() > 0) {
			this->text.pop_back();
		}
		this->text.pop_back();
	}
}

char Textbox::getLastChar()
{	
	if (this->text.size() == 0) {
		return '|';
	}
	return this->text[this->text.size() - 1];
}

void Textbox::onClick(bool isMouseEntered)
{
	if (isMouseEntered){
		this->isSelected = true;
	}
	else {
		this->isSelected = false;
	}
}

void Textbox::onMouseOver(bool isMouseEntered)
{

	if (this->isSelected) {
		this->textComponent.setFillColor(this->txtSelectedColor);
		this->background.setFillColor(this->bgSelectedColor);
	}
	else {
		if (isMouseEntered) {
			this->textComponent.setFillColor(this->txtMouseOverColor);
			this->background.setFillColor(this->bgMouseOverColor);
		}
		else {
			this->textComponent.setFillColor(this->txtDefaultColor);
			this->background.setFillColor(this->bgDefaultColor);
		}
	}
	
}

void Textbox::onInput(int character)
{
	if (character == 8){
		this->removeLastChar();
	}
	else {
		if (this->getLastChar() == '_') {
			this->text.pop_back();
		}
		this->text.push_back((char)character);
		this->text.push_back('_');

	}

}

void Textbox::update()
{
	if (this->text.empty()) {
		this->textComponent.setString(this->textPlaceHolder);
	}
	else {
		this->textComponent.setString(this->text);
	}

	if (this->isSelected) {
		if (this->getLastChar() != '_' && this->text.size() > 0) {
			this->text.push_back('_');
		}
	}
	else {
		if (this->getLastChar() == '_') {
			this->text.pop_back();
		}
	}
	if (this->text.size() > this->maxCharLength) {
		this->removeLastChar();
	}
}

void Textbox::render(sf::RenderWindow* win)
{
	if (!this->isVisible) { return; }
	win->draw(this->background);
	win->draw(this->textComponent);
}
