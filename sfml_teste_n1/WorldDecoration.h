#pragma once

#include <SFML/Graphics.hpp>

#ifndef WORLDDECORATION_H
#define WORLDDECORATION_H

class WorldDecoration
{
private:
public:
	sf::Vector2f initialSize;
	sf::Vector2f initialPosition;

	sf::Color color;
	sf::Texture* texture;
	sf::IntRect uv;
	sf::RectangleShape sprite;

	WorldDecoration();
	WorldDecoration(sf::Texture *txt, sf::Vector2f size = sf::Vector2f(192.f, 192.f), sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
	~WorldDecoration();

	void initVariables();
	void update();
	void render(sf::RenderWindow* win);

};


#endif



