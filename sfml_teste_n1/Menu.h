#pragma once

#include <SFML/Graphics.hpp>
#include "GUI_Controls.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
private:
public:
	GUI_Controls controls;

	sf::RectangleShape background;
	sf::Text textComponent;

	std::string title;
	float charSize;
	sf::Color titleColor;

	sf::Vector2f initialSize;
	sf::Vector2f initialPosition;

	sf::Font* font;
	sf::Texture* texture;

	bool isVisible;
	float verticalControlsSpacing;

	Menu();
	Menu(sf::Texture* texture, sf::Font* font, sf::Vector2f initialSize, std::string title = std::string("Default Title"), sf::Vector2f intialPosition = sf::Vector2f(0.f, 0.f));
	~Menu();

	void initVariables();

	void update();
	void render(sf::RenderWindow* win);

};

#endif
