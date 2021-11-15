#pragma once

#include <SFML/Graphics.hpp>
#include "FileManager.h"

#ifndef CONFIG_H
#define CONFIG_H
class Config
{
private:
public:

	float tileSize;
	float playerSize;
	unsigned int bitsPerPixel;
	unsigned int frameRateLimit;
	sf::Vector2u resolution;

	std::string configPathName;
	FileManager configManager;

	Config();
	Config(std::string config_pathName);
	~Config();

	void initVariables();
	void loadConfigurations();

};

#endif