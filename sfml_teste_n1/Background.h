#pragma once

#include <SFML/Graphics.hpp>

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
private:
public:

	sf::Vector2f initialPosition;
	sf::Vector2f initialSize;

	sf::IntRect uv;

	sf::Color color;
	sf::RectangleShape sprite;

	Background();
	Background(sf::Vector2f size, sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
	~Background();

	void initVariables();

	void update();
	void render(sf::RenderWindow* _win);
};

#endif
