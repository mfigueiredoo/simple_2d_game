#pragma once

#include <SFML/Graphics.hpp>

#ifndef WORLDTILE_H
#define WORLDTILE_H

class WorldTile
{

private:

public:

	int type;
	bool isCollidable;

	sf::Vector2f initialPosition;
	sf::Vector2f initialSize;
	sf::RectangleShape sprite;

	sf::Vector2f realtimePosition;
	sf::Vector2f offSetPosition;
	sf::Vector2f center;


	float top;
	float left;
	float right;
	float bottom;

	WorldTile();
	WorldTile(sf::Vector2f _position, float tileSize, int type = 0);
	~WorldTile();

	void initVariables();

	void update();
	void render(sf::RenderWindow* _win);

};

#endif

