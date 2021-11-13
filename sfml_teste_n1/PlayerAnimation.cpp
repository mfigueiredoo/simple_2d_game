#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation()
{
	this->initVariables();
}

PlayerAnimation::PlayerAnimation(sf::IntRect idleUV)
{
	this->initVariables();
	this->idle = idleUV;
	this->realTimeUV = this->idle;
}

PlayerAnimation::~PlayerAnimation()
{
}

void PlayerAnimation::initVariables()
{
	// Private Variables
	this->clock = sf::Clock();
	this->timePerSprite = 25.f;

	// Public Variables
	this->idle = sf::IntRect(0, 0, 0, 0);
	this->walk_1 = sf::IntRect(0, 0, 0, 0);
	this->walk_2 = sf::IntRect(0, 0, 0, 0);

	this->realTimeUV = sf::IntRect();
}

sf::IntRect PlayerAnimation::getRealtimeUV()
{
	return this->realTimeUV;
}

void PlayerAnimation::update(sf::RectangleShape *sprite, float dt, bool isJumping, bool isMoving, int Xdirection)
{

	// Invert sprite horizontaly by direction
	sprite->setScale(Xdirection, 1);

	if (isJumping) { this->realTimeUV = this->walk_1; return; }

	if (this->clock.getElapsedTime().asSeconds() > this->timePerSprite * dt && isMoving) {
		if (this->realTimeUV == this->walk_1) {
			this->realTimeUV = this->walk_2;
			this->clock.restart();
		}
		else {
			this->realTimeUV = this->walk_1;
			this->clock.restart();
		}
	}

	

	if (!isMoving) { this->realTimeUV = this->idle; }

}

