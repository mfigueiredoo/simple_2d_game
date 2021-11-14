#include "Label.h"

sf::Vector2f Label::textAlign(std::string align)
{
	float txtTop = this->textComponent.getGlobalBounds().top;
	float txtLeft = this->textComponent.getGlobalBounds().left;
	float txtHeight = this->textComponent.getGlobalBounds().height;
	float txtWidth = this->textComponent.getGlobalBounds().width;

	float bgTop = this->background.getGlobalBounds().top;
	float bgLeft = this->background.getGlobalBounds().left;
	float bgHeight = this->background.getGlobalBounds().height;
	float bgWidth = this->background.getGlobalBounds().width;

	sf::Vector2f txtPosition;

	if (align == "center") {
		txtPosition.x = (bgLeft + (bgWidth / 2)) - txtWidth / 2;
	}

	if (align == "left") {
		txtPosition.x = bgLeft;
	}

	if (align == "right") {
		txtPosition.x = ((bgLeft + bgWidth) - txtWidth);
}

	txtPosition.y = (bgTop + (bgHeight / 2)) - txtHeight / 2;

	return txtPosition;

}

Label::Label()
{
	this->initVariables();
}

Label::Label(sf::Font* font, std::string text, sf::Vector2f size, sf::Vector2f pos, float charSize, sf::Vector2f padding)
{
	this->initVariables();
	this->text = text;
	this->charSize = charSize;
	this->font = font;
	this->size = size;
	this->position = pos;
	this->padding = padding;

	this->textComponent.setFillColor(this->txtDefaultColor);
	this->textComponent.setString(this->text);
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setFont(*this->font);

	this->minSize = sf::Vector2f(textComponent.getGlobalBounds().width, textComponent.getGlobalBounds().height);

	if (this->size.x > this->minSize.x) { this->currentSize.x = this->size.x; }
	else { this->currentSize.x = this->minSize.x; }

	if (this->size.y > this->minSize.y) { this->currentSize.y = this->size.y; }
	else { this->currentSize.y = this->minSize.y; }

	this->currentSize.x += this->padding.x * 2;
	this->currentSize.y += this->padding.y * 2;

	this->background.setFillColor(this->bgDefaultColor);
	this->background.setSize(this->currentSize);
	this->background.setPosition(this->position);

	this->textComponent.setPosition(textAlign(this->align));

}


Label::~Label()
{
}


void Label::initVariables()
{
	this->text = std::string("Label");
	this->charSize = 24.f;
	this->font = nullptr;
	this->align = "left";
	this->textComponent = sf::Text();
	this->background = sf::RectangleShape();
}

void Label::update()
{
	this->textComponent.setFillColor(this->txtDefaultColor);
	this->textComponent.setString(this->text);
	this->textComponent.setCharacterSize(this->charSize);
	this->textComponent.setFont(*this->font);
	this->textComponent.setPosition(textAlign(this->align));

	this->background.setFillColor(this->bgDefaultColor);
	this->background.setSize(this->currentSize);
	this->background.setPosition(this->position);
}

void Label::render(sf::RenderWindow* win)
{
	win->draw(this->background);
	win->draw(this->textComponent);
}
