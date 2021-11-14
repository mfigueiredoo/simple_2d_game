#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef ITEMCOMBOBOX_H
#define ITEMCOMBOBOX_H

class ItemComboBox
{
private:
	sf::Vector2f getTextCenterAlignmentPosition(sf::RectangleShape rect, sf::Text txtComponent);
public:

	int index;
	std::string text;

	float charSize;

	sf::Font* font;

	sf::Vector2f initialSize;
	sf::Vector2f currentSize;

	sf::Vector2f initialPosition;
	sf::Vector2f currentPosition;

	sf::RectangleShape background;
	sf::Text textComponent;

	sf::Color bgDefaultColor = sf::Color(255, 255, 255, 255);
	sf::Color bgMouseOverColor = sf::Color(32, 32, 32, 255);
	sf::Color bgSelectedColor = sf::Color(255, 255, 255, 255);

	sf::Color txtDefaultColor = sf::Color(0, 0, 0, 255);
	sf::Color txtMouseOverColor = sf::Color(0, 255, 255, 255);
	sf::Color txtSelectedColor = sf::Color(0, 0, 0, 255);

	bool isVisible;
	bool isMouseOver;
	bool isSelected;

	ItemComboBox();
	ItemComboBox(sf::Font* font, std::string text, int index, sf::Vector2f size = sf::Vector2f(256.f, 0.f), sf::Vector2f pos = sf::Vector2f(0.f, 0.f), float charSize = 24.f);
	~ItemComboBox();

	void onMouseOver(bool trueIfMouseEntered);
	int onClick(bool isMouseEntered);

	void initVariables();

	void update(bool isSelected);
	void render(sf::RenderWindow* _win);

};

#endif