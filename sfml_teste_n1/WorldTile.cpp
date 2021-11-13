#include "WorldTile.h"

WorldTile::WorldTile()
{
	this->initVariables();
}

WorldTile::WorldTile(sf::Vector2f _pos, float _tileSize, int _type)
{
	this->initVariables();

	this->type = _type;

	this->initialPosition = _pos;
	this->initialSize = sf::Vector2f(_tileSize, _tileSize);

	this->sprite.setPosition(this->initialPosition);
	this->sprite.setSize(sf::Vector2f(_tileSize, _tileSize));

	//this->sprite.setFillColor(this->color); // Just for test
}

WorldTile::~WorldTile()
{
}

void WorldTile::initVariables()
{
	this->type = 32;
	this->isCollidable = false;

	this->initialPosition = sf::Vector2f();
	this->initialSize = sf::Vector2f();
	this->sprite = sf::RectangleShape();

	this->realtimePosition = sf::Vector2f(0.f, 0.f);
	this->offSetPosition = sf::Vector2f(0.f, 0.f);
	this->center = sf::Vector2f(0.f, 0.f);

	this->top = 0.f;
	this->left = 0.f;
 	this->right = 0.f;
	this->bottom = 0.f;

}

void WorldTile::update()
{

	sf::IntRect uv = sf::IntRect();

	if (this->type == 32) { // Transparent ' '
		uv = sf::IntRect(0, 0, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 33) {  // LeftBricks '!'
		uv = sf::IntRect(64, 0, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 34) { // CenterBricks '"'
		uv = sf::IntRect(128, 0, 64, 64);
		this->isCollidable = true;
	}
	if (this->type == 35) { // RightBricks "#"
		uv = sf::IntRect(192, 0, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 36) { // leftCLineBricks '$'
		uv = sf::IntRect(256, 0, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 37) { // BottomLeftBricks '%'
		uv = sf::IntRect(64, 64, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 38) { // BottomCenterBricks '&'
		uv = sf::IntRect(128, 64, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 39) { // BottomRightBricks '''
		uv = sf::IntRect(192, 64, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 40) { // rightCLineBricks '('
		uv = sf::IntRect(320, 0, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 41) { // centerTopBricks ')'
		uv = sf::IntRect(128, 128, 64, 64);
		this->isCollidable = true;
	}
	if (this->type == 42) { // leftTopBricks '*'
		uv = sf::IntRect(64, 128, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 43) { // rightTopBricks '+'
		uv = sf::IntRect(192, 128, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 44) { // leftTopCLineBricks '*'
		uv = sf::IntRect(256, 128, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 45) { // rightTopClineBricks '-'
		uv = sf::IntRect(320, 128, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 46) { // rock '.'
		uv = sf::IntRect(0, 64, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 47) { // centerGround '/'
		uv = sf::IntRect(128, 192, 64, 64);
		this->isCollidable = true;
	}
	if (this->type == 48) { // LeftGround '0'
		uv = sf::IntRect(64, 192, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 49) { // RightGround '1'
		uv = sf::IntRect(192, 192, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 50) { // centerTopGround '2'
		uv = sf::IntRect(128, 256, 64, 64);
		this->isCollidable = true;
	}
	if (this->type == 51) { // LeftTopGround '3'
		uv = sf::IntRect(64, 256, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 52) { // RightTopGround '4'
		uv = sf::IntRect(192, 256, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 53) { // leftTopCornerGround '5'
		uv = sf::IntRect(64, 320, 64, 64);
		this->isCollidable = true;
	}
	if (this->type == 54) { // rightTopCornerGround '6'
		uv = sf::IntRect(192, 320, 64, 64);
		this->isCollidable = true;
	}
	if (this->type == 55) { // leftBottomCornerGround '7'
		uv = sf::IntRect(256, 320, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 56) { // centerBottomGround '8'
		uv = sf::IntRect(128, 320, 64, 64);
		this->isCollidable = false;
	}
	if (this->type == 57) { // rightBottomCornerGround '9'
		uv = sf::IntRect(320, 320, 64, 64);
		this->isCollidable = false;
	}


	this->sprite.setTextureRect(uv);

	this->realtimePosition = this->sprite.getPosition();

	this->top = this->sprite.getPosition().y + this->offSetPosition.y;
	this->left = this->sprite.getPosition().x + this->offSetPosition.x;
	this->right = this->sprite.getPosition().x + this->sprite.getSize().x + this->offSetPosition.x;
	this->bottom = this->sprite.getPosition().y + this->sprite.getSize().y + this->offSetPosition.y;

	this->center = sf::Vector2f((this->left + this->right) / 2, (this->top + this->bottom ) / 2);

}

void WorldTile::render(sf::RenderWindow* win)
{
	win->draw(this->sprite);
}
