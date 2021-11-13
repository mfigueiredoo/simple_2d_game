#include "MapManager.h"

MapManager::MapManager()
{
	this->initVariables();
}

MapManager::MapManager(std::string maps_pathName)
{
	this->initVariables();
	this->fileName = maps_pathName + std::string("Data.map");
}

MapManager::~MapManager()
{
}

void MapManager::initVariables()
{
	this->fileName = "";
}

bool MapManager::fileIsEmpty(std::fstream& file)
{
	return file.peek() == std::fstream::traits_type::eof();
}

bool MapManager::fileIsEmpty(std::ifstream& file)
{
	return file.peek() == std::ifstream::traits_type::eof();
}


