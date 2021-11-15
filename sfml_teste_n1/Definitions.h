#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Config.h"
#include "GameEngine.h"

#ifndef DEFINITIONS_H
#define DEFINITIONS_H


std::string FONTS_PATH = "Resources\\Fonts\\";
std::string TEXTURES_PATH = "Resources\\Textures\\";
std::string MAPS_PATH = "Data\\Maps\\Data.map";
std::string CONFIG_PATH = "config.conf";

Config conf = Config(CONFIG_PATH);

unsigned int _WINDOW_WIDTH = conf.resolution.x;
unsigned int _WINDOW_HEIGHT = conf.resolution.y;
unsigned int _BITSPERPIXEL = conf.bitsPerPixel;
float _TILESIZE = conf.tileSize;
float _PLAYERSIZE = conf.playerSize;
unsigned int _FRAMERATE = conf.frameRateLimit;


// Init Window
sf::RenderWindow window(sf::VideoMode(_WINDOW_WIDTH, _WINDOW_HEIGHT, _BITSPERPIXEL), "Ready?", sf::Style::Fullscreen); //sf::Style::Fullscreen
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
