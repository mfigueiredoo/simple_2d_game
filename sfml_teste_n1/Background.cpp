#include "Background.h"

Background::Background()
{
	this->initVariables();
}

Background::Background(sf::Vector2f size, sf::Vector2f pos)
{
	this->initVariables();
	this->initialSize = size;
	this->initialPosition = pos;

	this->sprite.setSize(this->initialSize);
	this->sprite.setPosition(this->initialPosition);
	this->sprite.setTextureRect(this->uv);
}

Background::~Background()
{
}

void Background::initVariables()
{
	this->initialPosition = sf::Vector2f();
	this->initialSize = sf::Vector2f();

	this->uv = sf::IntRect(0, 0, 480, 270);
	this->color = sf::Color(255, 255, 255, 127);
	this->sprite = sf::RectangleShape();
}

void Background::update()
{
	this->sprite.setTextureRect(this->uv);
	this->sprite.setFillColor(this->color);

}

void Background::render(sf::RenderWindow *_win)
{
	_win->draw(this->sprite);
}
