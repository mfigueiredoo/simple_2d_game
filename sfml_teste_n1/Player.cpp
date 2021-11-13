#include "Player.h"
#include <cmath>
#include <iostream>

// Constructors / Destructors
Player::Player()
{
	initVariables();
}

Player::Player(sf::Vector2f _size, sf::Vector2f _pos)
{
	this->initVariables();

	this->initialSize = _size;
	this->initialPosition = _pos;

	this->offSetPosition = sf::Vector2f(-(this->initialSize.x / 2), -(this->initialSize.y / 2));

	this->sprite = sf::RectangleShape();
	this->sprite.setSize(this->initialSize);
	this->sprite.setPosition(this->initialPosition);
	this->sprite.setFillColor(sf::Color::White);

	this->anim = PlayerAnimation(sf::IntRect(64.f, 128.f, this->initialSize.x, this->initialSize.y));

	this->anim.walk_1 = sf::IntRect(128.f, 128.f, this->initialSize.x, this->initialSize.y);
	this->anim.walk_2 = sf::IntRect(0.f, 128.f, this->initialSize.x, this->initialSize.y);
}

Player::~Player()
{
}



// Private methods
sf::Vector2f Player::getMoveAcceleratedDirectionalSpeed(bool ctrls[])
{

	if (this->isActive)
	{
		if (ctrls[sf::Keyboard::Space]) {
			if (!this->isJumping && this->isOnGround)
			{
				this->jump();
			}

		}

		if ((ctrls[sf::Keyboard::A] || ctrls[sf::Keyboard::D] || ctrls[sf::Keyboard::Left] || ctrls[sf::Keyboard::Right]) && (this->isCollidingHorizontaly == false)) // X axis
		{
			if (ctrls[sf::Keyboard::A] || ctrls[sf::Keyboard::Left]) { this->moveAcceleration.x -= this->moveAccelerationValue; }
			if (ctrls[sf::Keyboard::D] || ctrls[sf::Keyboard::Right]) { this->moveAcceleration.x += this->moveAccelerationValue; }
		}
		else {
			if (this->moveAcceleration.x == 0) { this->moveAcceleration.x = 0.f; this->isCollidingHorizontaly == false; }
			else if (this->moveAcceleration.x > 0) { this->moveAcceleration.x -= this->moveAccelerationValue; }
			else if (this->moveAcceleration.x < 0) { this->moveAcceleration.x += this->moveAccelerationValue; }
		}

		if (this->moveAcceleration.x > 0 && this->moveAcceleration.x < this->moveAccelerationValue) { this->moveAcceleration.x = 0.f; }
		if (this->moveAcceleration.x < 0 && abs(this->moveAcceleration.x) < this->moveAccelerationValue) { this->moveAcceleration.x = 0.f; }


		if (this->moveAcceleration.x > 0 && this->moveAcceleration.x > this->moveMaxSpeed) { this->moveAcceleration.x = this->moveMaxSpeed; }
		if (this->moveAcceleration.x < 0 && abs(this->moveAcceleration.x) > this->moveMaxSpeed) { this->moveAcceleration.x = -this->moveMaxSpeed; }

		if (this->moveAcceleration.y > 0 && this->moveAcceleration.y > this->moveMaxSpeed) { this->moveAcceleration.y = this->moveMaxSpeed; }
		if (this->moveAcceleration.y < 0 && abs(this->moveAcceleration.y) > this->moveMaxSpeed) { this->moveAcceleration.y = -this->moveMaxSpeed; }

		if (this->moveAcceleration.y > 0 && this->moveAcceleration.y < this->moveAccelerationValue) { this->moveAcceleration.y = 0.f; }
		if (this->moveAcceleration.y < 0 && abs(this->moveAcceleration.y) < this->moveAccelerationValue) { this->moveAcceleration.y = 0.f; }


		this->moveAcceleratedDirectionalSpeed = sf::Vector2f(this->moveAcceleration.x, this->moveAcceleration.y);

		// IsMoving Detetion
		if (this->isCollidingHorizontaly) { this->isMoving = false; }
		if (this->moveAcceleratedDirectionalSpeed.x != 0) { this->isMoving = true; }
		else if (this->moveAcceleratedDirectionalSpeed.x == 0) { this->isMoving = false; this->isCollidingHorizontaly = false; }

		return this->moveAcceleratedDirectionalSpeed;
	}

	return sf::Vector2f(0.f, 0.f);
}


// Public methods
void Player::initVariables()
{
	// Private
	

	// Public
	this->initialSize = sf::Vector2f();
	this->initialPosition = sf::Vector2f();
	this->offSetPosition = sf::Vector2f();
	this->realtimePosition = sf::Vector2f();
	this->realtimePositionWithOffset = sf::Vector2f();

	this->sprite = sf::RectangleShape();

	this->anim = PlayerAnimation();
	
	this->direction = 1;

	this->isJumping = true;
	this->isOnGround = false;
	this->isMoving = false;
	this->isCollidingHorizontaly = false;

	

	this->moveMaxSpeed = 500.f;
	this->moveAccelerationValue = 10.f;
	this->moveAcceleration.x = 0;
	this->moveAcceleration.y = 0;
	this->moveAcceleratedDirectionalSpeed = sf::Vector2f();

	this->gravityMaxSpeed = 500.f;
	this->gravityAccelarationValue = 5.f;
	this->gravityAccelaration = sf::Vector2f();
	this->gravityAcceleratedDirectionalSpeed = sf::Vector2f();

	this->jumpSize = 1024.f;
	this->jumpInitialPositionY = 0.f;
	this->jumpFinalPositionY = 0.f;

	this->jumpMaxSpeed = (this->gravityMaxSpeed * 2) * -1;
	this->jumpAccelarationValue = -10.f;
	this->jumpAccelaration = sf::Vector2f();
	this->jumpAcceleratedDirectionalSpeed = sf::Vector2f();

}

void Player::jump()
{
		this->isJumping = true;

		this->jumpInitialPositionY = this->realtimePositionWithOffset.y;
		this->jumpFinalPositionY = this->jumpInitialPositionY - this->jumpSize;
		
		this->jumpAccelaration = sf::Vector2f(0.f, this->jumpMaxSpeed);

}

void Player::jumpReset()
{
	this->jumpAccelaration = sf::Vector2f(0.f, 0.f);
	this->isJumping = false;
}

void Player::jumpUpdate()
{
	
	if (this->jumpAccelaration.y <= 0
		&& (abs(this->jumpAccelaration.y) - abs(this->jumpAccelarationValue)) <= abs(this->jumpAccelarationValue)) {
		this->jumpAccelaration = sf::Vector2f(0.f, 0.f);
	}
	if (this->jumpAccelaration.y < 0) {
		this->jumpAccelaration.y -= this->jumpAccelarationValue;
	}

	this->jumpAcceleratedDirectionalSpeed = this->jumpAccelaration;

}

void Player::gravityUpdate()
{
	this->gravityAccelaration.y += this->gravityAccelarationValue;
	this->gravityAcceleratedDirectionalSpeed = this->gravityAccelaration;
}

void Player::gravityReset()
{
	this->gravityAccelaration = sf::Vector2f(0.f, 0.f);
	this->isOnGround = true;
}

void Player::reset()
{
	this->sprite.setSize(this->initialSize);
	this->sprite.setPosition(this->initialPosition);
	this->sprite.setFillColor(sf::Color::White);

	this->anim = PlayerAnimation(sf::IntRect(64.f, 128.f, this->initialSize.x, this->initialSize.y));

	this->anim.walk_1 = sf::IntRect(128.f, 128.f, this->initialSize.x, this->initialSize.y);
	this->anim.walk_2 = sf::IntRect(0.f, 128.f, this->initialSize.x, this->initialSize.y);

	this->isJumping = true;
	this->isOnGround = false;
	this->isMoving = false;
	this->isCollidingHorizontaly = false;

	this->direction = 1;

	this->moveAcceleration = sf::Vector2f(0.f, 0.f);
	this->moveAcceleratedDirectionalSpeed = sf::Vector2f(0.f, 0.f);

	this->gravityAccelaration = sf::Vector2f(0.f, 0.f);
	this->gravityAcceleratedDirectionalSpeed = sf::Vector2f(0.f, 0.f);

	this->jumpAccelaration = sf::Vector2f(0.f, 0.f);
	this->jumpAcceleratedDirectionalSpeed = sf::Vector2f(0.f, 0.f);

}



void Player::update(bool controls[], bool isMainMenuVisible, float dt)
{
	this->isActive = !isMainMenuVisible;

	this->sprite.setTextureRect(this->anim.getRealtimeUV());

	// Vector contains Directional Accelaration of Motion
	sf::Vector2f _acceleratedDirectionalSpeed = this->getMoveAcceleratedDirectionalSpeed(controls);

	// Vector add Gravity
	this->gravityUpdate();
	_acceleratedDirectionalSpeed += this->gravityAcceleratedDirectionalSpeed;

	// Vector add Directional Acceleration of Jump
	this->jumpUpdate();
	_acceleratedDirectionalSpeed += this->jumpAcceleratedDirectionalSpeed;

	// DeltaTime Multiplication
	_acceleratedDirectionalSpeed = sf::Vector2f(_acceleratedDirectionalSpeed.x * dt, _acceleratedDirectionalSpeed.y * dt);

	// Move the sprite
	this->sprite.move(_acceleratedDirectionalSpeed);

	// Getting Direction of Player in X axis
	if (_acceleratedDirectionalSpeed.x != 0) {
		if (_acceleratedDirectionalSpeed.x > 0) { this->direction = 1; }
		if (_acceleratedDirectionalSpeed.x < 0) { this->direction = -1; }
	}

	this->anim.update(&this->sprite, dt, this->isJumping, this->isMoving, this->direction);

	// Update positions and add offSet
	sf::Vector2f originSpritePosition = this->sprite.getPosition();
	this->realtimePosition = originSpritePosition;


	this->realtimePositionWithOffset = sf::Vector2f(originSpritePosition.x + this->offSetPosition.x, originSpritePosition.y + this->offSetPosition.y);

	// Update Bounds

	this->top = this->sprite.getPosition().y + this->offSetPosition.y;
	this->left = this->sprite.getPosition().x + this->offSetPosition.x;
	this->right = this->sprite.getPosition().x + this->sprite.getSize().x + this->offSetPosition.x;
	this->bottom = this->sprite.getPosition().y + this->sprite.getSize().y + this->offSetPosition.y;

	this->center = sf::Vector2f((this->left + this->right) / 2, (this->top + this->bottom) / 2);

}

void Player::render(sf::RenderWindow* win)
{
	win->draw(this->sprite);
}
