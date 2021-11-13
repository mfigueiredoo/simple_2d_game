#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ItemComboBox.h"

#ifndef COMBOBOX_H
#define COMBOBOX_H

class ComboBox
{
private:
	sf::Vector2f getTextCenterAlignmentPosition(sf::RectangleShape rect, sf::Text txtComponent);
	void sizeAjustment();
public:

	sf::Font* font;
	float charSize;

	sf::Vector2f padding;
	sf::Vector2f minSize;
	sf::Vector2f initialSize;
	sf::Vector2f currentSize;

	sf::Vector2f initialPosition;

	std::vector<ItemComboBox> items;
	int selectedItemIndex = -1;

	sf::RectangleShape background;
	sf::Text textComponent;
	sf::RectangleShape dropButton;

	char dropButtonArrow;
	sf::Text dropButtonArrowComponent;

	sf::Color bgDefaultColor = sf::Color(32, 32, 32, 255);
	sf::Color bgMouseOverColor = sf::Color(255, 255, 255, 127);
	sf::Color bgActiveColor = sf::Color(0, 0, 0, 255);

	sf::Color txtDefaultColor = sf::Color(200, 255, 255, 255);
	sf::Color txtMouseOverColor = sf::Color(200, 255, 255, 255);
	sf::Color txtActiveColor = sf::Color(200, 255, 255, 255);

	sf::Color borderDefaultColor = sf::Color(130, 220, 215, 255);
	sf::Color borderMouseOverColor = sf::Color(130, 220, 215, 255);
	sf::Color borderActiveColor = sf::Color(130, 220, 215, 255);

	sf::Color bgDropButtonDefaultColor = sf::Color(130, 220, 215, 255);
	sf::Color bgDropButtonMouseOverColor = sf::Color(130, 220, 215, 255);
	sf::Color bgDropButtonActiveColor = sf::Color(130, 220, 215, 255);
	
	sf::Color txtDropButtonDefaultColor = sf::Color(0, 0, 0, 255);
	sf::Color txtDropButtonMouseOverColor = sf::Color(0, 0, 0, 255);
	sf::Color txtDropButtonActiveColor = sf::Color(0, 0, 0, 255);

	bool isVisible;
	bool isMouseOver;
	bool isActive;

	ComboBox();
	ComboBox(sf::Font* font, sf::Vector2f size = sf::Vector2f(256.f, 0.f), sf::Vector2f pos = sf::Vector2f(64.f, 64.f), float charSize = 24.f, sf::Vector2f padding = sf::Vector2f(16.f, 8.f));
	~ComboBox();


	void initVariables();

	void onMouseOver(bool trueIfMouseEntered);
	void onClick(bool isMouseEntered);

	void addItem(ItemComboBox item);

	void update();
	void render(sf::RenderWindow* _win);

};

#endif



