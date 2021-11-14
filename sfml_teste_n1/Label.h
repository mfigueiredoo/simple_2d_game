#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#ifndef LABEL_H
#define LABEL_H
class Label
{
private:
public:

	std::string text;
	float charSize;
	sf::Font* font;
	std::string align;
	sf::Vector2f padding;

	sf::Vector2f size;
	sf::Vector2f minSize;
	sf::Vector2f currentSize;

	sf::Vector2f position;

	sf::Text textComponent;
	sf::RectangleShape background;

	sf::Color bgDefaultColor = sf::Color::Transparent;
	sf::Color txtDefaultColor = sf::Color(255, 255, 255, 255);

	Label();
	Label(sf::Font* font, std::string text, sf::Vector2f size = sf::Vector2f(0.f, 0.f), sf::Vector2f pos = sf::Vector2f(256.f, 256.f), float charSize = 16.f, sf::Vector2f padding = sf::Vector2f(16.f, 8.f));
	~Label();

	sf::Vector2f textAlign(std::string align = std::string("center"));

	void initVariables();

	void update();
	void render(sf::RenderWindow* _win);

};

#endif