#pragma once

#include <SFML/Graphics.hpp>

#ifndef TEXTBOX_H
#define TEXTBOX_H

class Textbox
{
private:
public:


	std::string text;
	std::string emptyStringWithMaxCharLength;
	std::string textPlaceHolder;

	sf::Text textComponent;
	sf::RectangleShape background;

	sf::Color txtDefaultColor;
	sf::Color txtMouseOverColor;
	sf::Color txtSelectedColor;

	sf::Color bgDefaultColor;
	sf::Color bgMouseOverColor;
	sf::Color bgSelectedColor;


	float charSize;
	sf::Vector2f padding;
	sf::Vector2f initialPosition;
	sf::Vector2f initialSize;

	int maxCharLength;


	bool isVisible;
	bool isSelected;

	Textbox();
	Textbox(sf::Font* font, sf::Vector2f pos = sf::Vector2f(256.f, 128.f), float size = 16.f, sf::Vector2f padding = sf::Vector2f(12.f, 12.f));
	~Textbox();

	void initVariables();

	void textCenter();

	void removeLastChar();
	char getLastChar();

	void onClick(bool isMouseEntered);
	void onMouseOver(bool isMouseEntered);
	void onInput(int character);

	void update();
	void render(sf::RenderWindow* _win);

};
#endif



