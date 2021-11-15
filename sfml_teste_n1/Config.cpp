#include "Config.h"

Config::Config()
{
	this->initVariables();
	this->loadConfigurations();
}

Config::Config(std::string config_pathName)
{
	this->initVariables();
	this->configPathName = config_pathName;
	this->configManager = FileManager(this->configPathName);

	this->loadConfigurations();
}

Config::~Config()
{
}

void Config::initVariables()
{
	this->tileSize = 64.f;
	this->playerSize = 64.f;
	this->bitsPerPixel = 16;
	this->resolution = sf::Vector2u(800, 600);
	this->configPathName = "";
	this->configManager = FileManager();

	
}

void Config::loadConfigurations()
{
	std::string file_name = this->configManager.fileName;

	std::ifstream file(file_name);

	if (file.is_open()) {
		if (this->configManager.fileIsEmpty(file)) {
			std::cout << "[WARNIG] - File \"" << file_name << "\" is EMPTY. Is not possible loading game configurations.\n" << std::endl;
			file.close();
		}
		else {

			std::string fileLine;

			std::string width;
			std::string height;
			std::string bitsPerPixel;
			std::string tileSize;
			std::string playerSize;
			std::string frameRate;

			while (std::getline(file, fileLine))
			{
				for (size_t i = 0; i < fileLine.size(); i++)
				{
					if ( (char)fileLine[0] == 'W') {
						if (i != 0) {
							width.push_back((char)fileLine[i]);
						}
					}

					if ((char)fileLine[0] == 'H') {
						if (i != 0) {
							height.push_back((char)fileLine[i]);
						}
					}

					if ((char)fileLine[0] == 'U') {
						if (i != 0) {
							bitsPerPixel.push_back((char)fileLine[i]);
						}
					}

					if ((char)fileLine[0] == 'T') {
						if (i != 0) {
							tileSize.push_back((char)fileLine[i]);
						}
					}

					if ((char)fileLine[0] == 'P') {
						if (i != 0) {
							playerSize.push_back((char)fileLine[i]);
						}
					}

					if ((char)fileLine[0] == 'F') {
						if (i != 0) {
							frameRate.push_back((char)fileLine[i]);
						}
					}

				}
			}

			this->resolution.x = std::stoi(width);
			this->resolution.y = std::stoi(height);
			this->bitsPerPixel = std::stoi(bitsPerPixel);
			this->tileSize = std::stof(tileSize);
			this->playerSize = std::stof(playerSize);
			this->frameRateLimit = std::stoi(frameRate);

			//Debug
			std::cout << this->resolution.x << std::endl;
			std::cout << this->resolution.y << std::endl;
			std::cout << this->bitsPerPixel << std::endl;
			std::cout << this->tileSize << std::endl;
			std::cout << this->playerSize << std::endl;
			std::cout << this->frameRateLimit << std::endl;

			file.close();
		}
	}
	else {
		std::cout << "[WARNING] - File \"" << file_name << "\" is NOT OPEN. Is not possible loading game configurations.\n" << std::endl;
	}

}
