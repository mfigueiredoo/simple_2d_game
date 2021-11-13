#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#ifndef PLAYER_ANIMATION_H
#define PLAYER_ANIMATION_H

class PlayerAnimation
{
private:

	sf::Clock clock;
	float timePerSprite;

public:

	PlayerAnimation();
	PlayerAnimation(sf::IntRect);
	~PlayerAnimation();

	sf::IntRect idle;
	sf::IntRect walk_1;
	sf::IntRect walk_2;

	sf::IntRect realTimeUV;

	void initVariables();
	sf::IntRect getRealtimeUV();

	void update(sf::RectangleShape*, float, bool, bool, int);
};

#endif

