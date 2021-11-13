#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventHandler.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
private:

	void initVariables();
	void textCenter();

public:

	sf::Color bgDefaultColor = sf::Color(0, 0, 0, 255);
	sf::Color txtDefaultColor = sf::Color(200, 255, 255, 255);
	sf::Color borderDefaultColor = sf::Color(130, 220, 215, 255);

	sf::Color bgMouseOverColor = sf::Color(130, 220, 215, 255);
	sf::Color txtMouseOverColor = sf::Color(0, 0, 0, 255);
	sf::Color borderMouseOverColor = sf::Color(200, 255, 255, 255);

	sf::Vector2f padding;
	sf::Vector2f minSize;
	sf::Vector2f size;
	sf::Vector2f currentSize;

	float charSize;

	std::string text;
	sf::Text textComponent;
	sf::Vector2f textPosition;
	sf::RectangleShape background;

	std::string name;

	bool isVisible = true;
	bool isMouseOver = false;

	Button();
	Button(sf::Font* font, std::string text, std::string name = "defaultName", sf::Vector2f size = sf::Vector2f(0.f, 0.f),  sf::Vector2f pos = sf::Vector2f(256.f, 256.f), float charSize = 16.f, sf::Vector2f padding = sf::Vector2f(16.f, 8.f));
	~Button();

	
	void onMouseOver(bool trueIfMouseEntered);
	void onClick(bool isMouseEntered);

	EventHandler click;

	void update();
	void render(sf::RenderWindow* win);
};

#endif


