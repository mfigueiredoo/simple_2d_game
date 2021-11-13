#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "GameEngine.h"

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

const int _WINDOW_WIDTH = 1920;
const int _WINDOW_HEIGHT = 1080;
const int _BITSPERPIXEL = 32;
const float _TILESIZE = 64.f;
const float _PLAYERSIZE = 64.f;
const int _FRAMERATE = 165;

std::string FONTS_PATH = "Resources\\Fonts\\";
std::string TEXTURES_PATH = "Resources\\Textures\\";
std::string MAPS_PATH = "Data\\Maps\\";

// Init Window
sf::RenderWindow window(sf::VideoMode(_WINDOW_WIDTH, _WINDOW_HEIGHT, _BITSPERPIXEL), "sfml_teste_n1", sf::Style::Fullscreen); //sf::Style::Fullscreen
GameEngine gameEngine(&window, _TILESIZE, _FRAMERATE);

void init() {

    gameEngine.window->setFramerateLimit(gameEngine.getFramerateLimit());
}


// shared Event Handlers
    // Click
void defaultClickHandler() {
    return;
}

// MainMenu Event Handlers
    // Click
void playClickHandler()
{
    gameEngine.reset();

    if (gameEngine.mainMenu.isVisible)
        gameEngine.mainMenu.isVisible = false;

    if (gameEngine.isPaused == true)
        gameEngine.isPaused = false;

    std::cout << "EventHandler playHandler() called in Main.cpp" << std::endl;
    return;
}

void configClickHandler()
{
    gameEngine.mainMenu.isVisible = false;
    gameEngine.configMenu.isVisible = true;
    std::cout << "EventHandler configHandler() called in Main.cpp" << std::endl;
    return;
}



void exitClickHanlder()
{
    gameEngine.window->close();
    std::cout << "EventHandler exitHanlder() called in Main.cpp" << std::endl;
    return;
}

// PauseMenu Event Handlers
    // Click
void resumeClickHandler()
{
    if (gameEngine.pauseMenu.isVisible)
        gameEngine.pauseMenu.isVisible = false;

    if (gameEngine.isPaused == true)
        gameEngine.isPaused = false;

    std::cout << "EventHandler resumeHandler() called in Main.cpp" << std::endl;
    return;
}

void gotoMainMenuClickHandler()
{
    if (gameEngine.pauseMenu.isVisible)
    {
        gameEngine.isPaused = false;
        gameEngine.reset();

        gameEngine.pauseMenu.isVisible = false;
        gameEngine.mainMenu.isVisible = true;
    }

    std::cout << "EventHandler restartHandler() called in Main.cpp" << std::endl;
    return;
}

void restartClickHandler()
{
    gameEngine.reset();

    if (gameEngine.mainMenu.isVisible)
        gameEngine.mainMenu.isVisible = false;

    if (gameEngine.pauseMenu.isVisible)
        gameEngine.pauseMenu.isVisible = false;

    if (gameEngine.isPaused)
        gameEngine.isPaused = false;

    std::cout << "EventHandler restartHandler() called in Main.cpp" << std::endl;
    return;
}

// ConfigMenu Event Handlers
    // Click

void backClickHandler() {

    gameEngine.configMenu.isVisible = false;
    gameEngine.mainMenu.isVisible = true;

    std::cout << "EventHandler backClickHandler() called in Main.cpp" << std::endl;
    return;
}

#endif
