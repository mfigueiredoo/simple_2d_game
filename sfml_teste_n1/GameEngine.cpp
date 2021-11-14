#include <stdio.h>
#include "GameEngine.h"
#include <iostream>


GameEngine::GameEngine()
{
    this->initVariables();
}

GameEngine::GameEngine(sf::RenderWindow* _win, float _tileSize, int _frameRate)
{
	this->initVariables();
	this->window = _win;
    this->tileSize = _tileSize;
    this->frameRate = _frameRate;
}

GameEngine::~GameEngine()
{
}

bool GameEngine::isMenuVisible()
{
    return (this->mainMenu.isVisible || this->pauseMenu.isVisible);
}

int GameEngine::getFramerateLimit()
{
    return this->frameRate;
}

int GameEngine::getTileSize()
{
    return this->tileSize;
}

void GameEngine::initVariables()
{
    for (size_t i = 0; i < sf::Keyboard::KeyCount; i++)
    {
        this->keys[i] = false;
    }

    this->clearColor = sf::Color(255, 255, 255, 255);

	this->window = nullptr;
    this->player = Player();
    this->world = World();

    this->intro = Intro();

    this->mainMenu = Menu();
    this->pauseMenu = Menu();
    this->configMenu = Menu();

    this->isPaused = false;

}

bool GameEngine::mouseOverRect(sf::Vector2i mousePosition, sf::Vector2f rectSize, sf::Vector2f rectPosition)
{
    if (mousePosition.x > rectPosition.x && mousePosition.x < rectSize.x
        && mousePosition.y > rectPosition.y && mousePosition.y < rectSize.y)
    {
        return true;
    }

    return false;
    
}

void GameEngine::controls_onClick(Menu &menu, sf::Event &e)
{
    //Buttons
    for (size_t i = 0; i < menu.controls.buttons.size(); i++)
    {
        if (e.type == sf::Event::MouseButtonPressed && menu.isVisible) {

            sf::Vector2i mousePos = sf::Mouse::getPosition();
            sf::Vector2f rect_pos = menu.controls.buttons[i].background.getPosition();
            sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.buttons[i].background.getGlobalBounds().width, rect_pos.y + menu.controls.buttons[i].background.getGlobalBounds().height);

            menu.controls.buttons[i].onClick(this->mouseOverRect(mousePos, rect_size, rect_pos));
        }
    }

    //Textboxes
    for (size_t i = 0; i < menu.controls.textboxes.size(); i++)
    {
        if (e.type == sf::Event::MouseButtonPressed && menu.isVisible) {

            sf::Vector2i mousePos = sf::Mouse::getPosition();
            sf::Vector2f rect_pos = menu.controls.textboxes[i].background.getPosition();
            sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.textboxes[i].background.getGlobalBounds().width, rect_pos.y + menu.controls.textboxes[i].background.getGlobalBounds().height);

            menu.controls.textboxes[i].onClick(this->mouseOverRect(mousePos, rect_size, rect_pos));
        }
    }

    //Comboboxes
    for (size_t i = 0; i < menu.controls.comboboxes.size(); i++)
    {
        if (e.type == sf::Event::MouseButtonPressed && menu.isVisible) {

            sf::Vector2i mousePos = sf::Mouse::getPosition();
            sf::Vector2f rect_pos = menu.controls.comboboxes[i].background.getPosition();
            sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.comboboxes[i].background.getGlobalBounds().width, rect_pos.y + menu.controls.comboboxes[i].background.getGlobalBounds().height);

            menu.controls.comboboxes[i].onClick(this->mouseOverRect(mousePos, rect_size, rect_pos));

            for (size_t j = 0; j < menu.controls.comboboxes[i].items.size(); j++)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                sf::Vector2f rect_pos = menu.controls.comboboxes[i].items[j].background.getPosition();
                sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.comboboxes[i].items[j].background.getGlobalBounds().width, rect_pos.y + menu.controls.comboboxes[i].items[j].background.getGlobalBounds().height);

                int selected_index = menu.controls.comboboxes[i].items[j].onClick(this->mouseOverRect(mousePos, rect_size, rect_pos));

                if (selected_index != -1) {
                    menu.controls.comboboxes[i].selectedItemIndex = selected_index;
                    menu.controls.comboboxes[i].items[j].isSelected = true;    
                }

            }

        }
    }

}
void GameEngine::controls_onMouseOver(Menu &menu, sf::Event &e)
{
    //Buttons
    for (size_t i = 0; i < menu.controls.buttons.size(); i++)
    {
        if (menu.isVisible)
        {
            sf::Vector2i mousePos = sf::Vector2i(e.mouseMove.x, e.mouseMove.y);
            sf::Vector2f rect_pos = menu.controls.buttons[i].background.getPosition();
            sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.buttons[i].background.getGlobalBounds().width, rect_pos.y + menu.controls.buttons[i].background.getGlobalBounds().height);

            menu.controls.buttons[i].onMouseOver(this->mouseOverRect(mousePos, rect_size, rect_pos));
        }
    }

    //Textboxes
    for (size_t i = 0; i < menu.controls.textboxes.size(); i++)
    {
        if (menu.isVisible)
        {
            sf::Vector2i mousePos = sf::Vector2i(e.mouseMove.x, e.mouseMove.y);
            sf::Vector2f rect_pos = menu.controls.textboxes[i].background.getPosition();
            sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.textboxes[i].background.getGlobalBounds().width, rect_pos.y + menu.controls.textboxes[i].background.getGlobalBounds().height);

            menu.controls.textboxes[i].onMouseOver(this->mouseOverRect(mousePos, rect_size, rect_pos));
        }
    }

    //Comboboxes
    for (size_t i = 0; i < menu.controls.comboboxes.size(); i++)
    {
        if (menu.isVisible)
        {
            sf::Vector2i mousePos = sf::Vector2i(e.mouseMove.x, e.mouseMove.y);
            sf::Vector2f rect_pos = menu.controls.comboboxes[i].background.getPosition();
            sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.comboboxes[i].background.getGlobalBounds().width, rect_pos.y + menu.controls.comboboxes[i].background.getGlobalBounds().height);

            menu.controls.comboboxes[i].onMouseOver(this->mouseOverRect(mousePos, rect_size, rect_pos));

            for (size_t j = 0; j < menu.controls.comboboxes[i].items.size(); j++)
            {
                sf::Vector2i mousePos = sf::Vector2i(e.mouseMove.x, e.mouseMove.y);
                sf::Vector2f rect_pos = menu.controls.comboboxes[i].items[j].background.getPosition();
                sf::Vector2f rect_size = sf::Vector2f(rect_pos.x + menu.controls.comboboxes[i].items[j].background.getGlobalBounds().width, rect_pos.y + menu.controls.comboboxes[i].items[j].background.getGlobalBounds().height);

                menu.controls.comboboxes[i].items[j].onMouseOver(this->mouseOverRect(mousePos, rect_size, rect_pos));

            }

        }
    }
}

void GameEngine::controls_onInput(Menu &menu, sf::Event &e, std::vector<Textbox> &textboxes)
{
    //Textboxes
    if (e.type == sf::Event::TextEntered && menu.isVisible) {
        for (size_t i = 0; i < textboxes.size(); i++)
        {
            if (e.text.unicode < 128) {
                if (textboxes[i].isSelected && textboxes[i].isVisible) {
                    textboxes[i].onInput(e.text.unicode);
                }
            }
        }
    }
}



void GameEngine::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        // Windows Controls
        if (this->event.type == sf::Event::Closed) { this->window->close(); }

        // Keyboard Controls
        if (this->event.type == sf::Event::KeyPressed) { this->keys[this->event.key.code] = true; }
        if (this->event.type == sf::Event::KeyReleased) { this->keys[this->event.key.code] = false; }
        
        // Game Pause 
        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Escape) {
                if (!this->pauseMenu.isVisible) {
                    if (!this->mainMenu.isVisible) {
                        this->pauseMenu.isVisible = true;
                        this->isPaused = true;
                    }
                }               
                else {
                    this->pauseMenu.isVisible = false;
                    this->isPaused = false;
                }
            }
        }

        if (this->event.type == sf::Event::MouseButtonPressed) {

            this->controls_onClick(this->mainMenu, this->event);
            this->controls_onClick(this->pauseMenu, this->event);
            this->controls_onClick(this->configMenu, this->event);
        }
        
        if (this->event.type == sf::Event::MouseMoved) {

            this->controls_onMouseOver(this->mainMenu, this->event);
            this->controls_onMouseOver(this->pauseMenu, this->event);
            this->controls_onMouseOver(this->configMenu, this->event);
        }
        
        if (this->event.type == sf::Event::TextEntered) {
            this->controls_onInput(this->mainMenu, this->event, this->mainMenu.controls.textboxes);
            this->controls_onInput(this->pauseMenu, this->event, this->pauseMenu.controls.textboxes);
            this->controls_onInput(this->configMenu, this->event, this->configMenu.controls.textboxes);
        }

    }
}

void GameEngine::collisionDetection()
{
    for (int i = 0; i < this->world.tiles.size(); i++)
    {
        WorldTile tile = this->world.tiles[i];

        if (tile.isCollidable) {

            sf::FloatRect resultRect = sf::FloatRect();
            sf::Vector2f theoreticalPos = sf::Vector2f(0.f, 0.f);

            if (this->player.sprite.getGlobalBounds().intersects(tile.sprite.getGlobalBounds(), resultRect)) {
                
                sf::Vector2f diferenceCenterToCenter = this->player.center - tile.center;

                // Top || Bottom
                if ( (diferenceCenterToCenter.y > 0 && abs(diferenceCenterToCenter.y) < tile.initialSize.y) || (diferenceCenterToCenter.y < 0 && abs(diferenceCenterToCenter.y) < tile.initialSize.y) )
                {
                    // Left || Right
                    if ((diferenceCenterToCenter.x > 0 || diferenceCenterToCenter.x < 0) && ( abs(diferenceCenterToCenter.y) < tile.initialSize.y - (tile.initialSize.y * 0.1 ) || (((float)((int)(abs(diferenceCenterToCenter.y) * 10))) / 10 == 0.f) ))
                    {
                        
                        // Left
                        if (diferenceCenterToCenter.x > 0) {
                            theoreticalPos += sf::Vector2f(resultRect.width, 0.f);
                        }
                            
                        // Right
                        if (diferenceCenterToCenter.x < 0)
                        {
                            theoreticalPos += sf::Vector2f(-resultRect.width, 0.f);
                        }

                    }
                    else {

                        // top
                        if (diferenceCenterToCenter.y > 0) {
                            this->player.jumpReset();
                            this->player.isOnGround = false;
                            theoreticalPos += sf::Vector2f(0.f, resultRect.height);
                        }
                        // Bottom
                            
                        if (diferenceCenterToCenter.y < 0) {

                            this->player.jumpReset();
                            this->player.gravityReset();
                            theoreticalPos += sf::Vector2f(0.f, -resultRect.height);

                        }

                    }
  
                }

                this->player.sprite.move(theoreticalPos);

                if (theoreticalPos.x != 0.f)
                {
                    this->player.isCollidingHorizontaly = true;
                    this->player.moveAcceleration.x = 0.f;
                }

                if (theoreticalPos.x == 0.f) { this->player.isCollidingHorizontaly = false; }

            }
        }
    }
}

void GameEngine::reset()
{
    this->player.reset();
    this->world.reset();
}

void GameEngine::update()
{

    bool mouseVisibility = true;

    mouseVisibility = (this->mainMenu.isVisible || this->pauseMenu.isVisible || this->configMenu.isVisible) && !this->intro.isVisible;
    this->window->setMouseCursorVisible(mouseVisibility);

    this->collisionDetection();

}
