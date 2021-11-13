#pragma once

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <type_traits>

#include "Player.h"
#include "World.h"
#include "Background.h"
#include "Menu.h"
#include "Intro.h"

class GameEngine
{
private:
	bool mouseOverRect(sf::Vector2i mousePosition, sf::Vector2f rectSize, sf::Vector2f rectPosition);
	
	
	void controls_onClick(Menu &m, sf::Event &e);
	void controls_onMouseOver(Menu &m, sf::Event &e);
	void controls_onInput(Menu &m, sf::Event &e, std::vector<Textbox> &textboxes);
public:

	float tileSize;
	int frameRate;

	sf::Color clearColor;

	Player player;
	World world;

	Intro intro;

	Menu mainMenu;
	Menu pauseMenu;
	Menu configMenu;

	sf::RenderWindow *window;
	sf::Event event;

	bool isPaused;
	bool keys[sf::Keyboard::KeyCount];

	GameEngine();
	GameEngine(sf::RenderWindow *_win, float tileSize, int frameRate);
	~GameEngine();

	bool isMenuVisible();

	int getFramerateLimit();
	int getTileSize();

	void initVariables();
	void pollEvents();

	void collisionDetection();

	void reset();

	void update();

};

#endif