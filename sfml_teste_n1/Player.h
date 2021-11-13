#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "PlayerAnimation.h"

#ifndef PLAYER_H
#define PLAYER_H



class Player
{
private:

	

public:

	sf::Vector2f initialSize;
	sf::Vector2f initialPosition;
	sf::Vector2f offSetPosition;
	sf::Vector2f realtimePosition;
	sf::Vector2f realtimePositionWithOffset;

	sf::RectangleShape sprite;
	
	PlayerAnimation anim;

	int direction;

	bool isJumping;
	bool isOnGround;
	bool isMoving;
	bool isCollidingHorizontaly;
	bool isActive;

	float moveMaxSpeed;
	float moveAccelerationValue;
	sf::Vector2f moveAcceleration;
	sf::Vector2f moveAcceleratedDirectionalSpeed;
	sf::Vector2f getMoveAcceleratedDirectionalSpeed(bool _ctrls[]);

	float gravityMaxSpeed;
	float gravityAccelarationValue;
	sf::Vector2f gravityAccelaration;
	sf::Vector2f gravityAcceleratedDirectionalSpeed;

	float jumpSize;
	float jumpInitialPositionY;
	float jumpFinalPositionY;

	float jumpMaxSpeed;
	float jumpAccelarationValue;
	sf::Vector2f jumpAccelaration;
	sf::Vector2f jumpAcceleratedDirectionalSpeed;

	sf::Vector2f center;
	float top;
	float left;
	float right;
	float bottom;

	Player();
	Player(sf::Vector2f initialSize, sf::Vector2f initialPosition);
	~Player();

	void initVariables();

	void jump();
	void jumpReset();

	void jumpUpdate();
	void gravityUpdate();
	void gravityReset();

	void reset();

	void update(bool ctrls[], bool isMainMenuVisible, float deltaTime);
	void render(sf::RenderWindow *_win);

};

#endif
