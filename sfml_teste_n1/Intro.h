#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef INTRO_H
#define INTRO_H
class Intro
{
private:

	void initVariables();

public:

	sf::Clock clock;
	sf::Vector2f initialSize;
	float visibleTime;
	bool isVisible;

	sf::RectangleShape banner;
	sf::RectangleShape background;
	sf::Color bgColor;
	sf::Color bannerColor;

	Intro();
	Intro(sf::Vector2f WindowSize);
	~Intro();

	void update(float dt);
	void render(sf::RenderWindow* win);
};
#endif


