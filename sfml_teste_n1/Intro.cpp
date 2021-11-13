#include "Intro.h"


Intro::Intro()
{
	this->initVariables();
}

Intro::Intro(sf::Vector2f size)
{
	this->initVariables();

	this->initialSize = size;

	this->banner.setSize(this->initialSize);
	this->banner.setFillColor(this->bannerColor);

	this->background.setSize(this->initialSize);
	this->background.setFillColor(this->bgColor);
	this->clock.restart();
}

Intro::~Intro()
{
}

void Intro::initVariables()
{
	this->initialSize = sf::Vector2f();
	this->visibleTime = 3.f;
	this->isVisible = true;

	this->banner = sf::RectangleShape();
	this->background = sf::RectangleShape();
	this->bgColor = sf::Color(0, 0, 0, 255);
	this->bannerColor = sf::Color(255, 255, 255, 0);
}

void Intro::update(float deltaTime)
{
	static float  a = 0;
	float  a_amount = 200.f * deltaTime;

	a += a_amount;

	if (this->bannerColor.a < 255 && a >= 1.f) { this->bannerColor += sf::Color(0, 0, 0, 1); a = 0; }


	if (this->clock.getElapsedTime().asSeconds() > this->visibleTime) {

		this->banner.setFillColor(sf::Color(255, 255, 255, this->bgColor.a));

		if (this->bgColor.a > 0  && a >= 1.f)
		{
			this->bgColor -= sf::Color(0, 0, 0, 1);
			a = 0.f;
			a_amount += 1500.f * deltaTime;
		}
		else if (this->bgColor.a <= 0)
		{
			this->isVisible = false;
		}
	}
	else {
		this->banner.setFillColor(this->bannerColor);
	}

	this->background.setFillColor(this->bgColor);

}

void Intro::render(sf::RenderWindow* win)
{
	if (!this->isVisible) { return; }
	win->draw(this->background);
	win->draw(this->banner);
}

