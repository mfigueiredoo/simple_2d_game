#include "WorldDecoration.h"

WorldDecoration::WorldDecoration()
{
	this->initVariables();
}

WorldDecoration::WorldDecoration(sf::Texture* txt, sf::Vector2f size, sf::Vector2f pos)
{
	this->initVariables();

	this->texture = txt;
	this->initialSize = size;
	this->initialPosition = pos;

	this->sprite.setSize(sf::Vector2f(192.f, 192.f)); //this->initialSize);
	this->sprite.setPosition(sf::Vector2f(576.f, 768.f));//this->initialPosition);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 192, 192)); //this->uv);

}

WorldDecoration::~WorldDecoration()
{
}

void WorldDecoration::initVariables()
{
	this->initialSize = sf::Vector2f();
	this->initialPosition = sf::Vector2f();

	this->color = sf::Color(127, 127, 127, 255);
	this->texture = nullptr;
	this->uv = sf::IntRect();
	this->sprite = sf::RectangleShape();

}

void WorldDecoration::update()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setFillColor(this->color);
}

void WorldDecoration::render(sf::RenderWindow* win )
{
	win->draw(this->sprite);
}
