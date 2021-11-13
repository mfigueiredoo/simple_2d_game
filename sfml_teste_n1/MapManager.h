#pragma once

#include <iostream>
#include <fstream>

#ifndef MAPMANAGER_H
#define MAPMANAGER_H

class MapManager
{
private:

public:

	std::string fileName;

	MapManager();
	MapManager(std::string maps_pathName);
	~MapManager();

	void initVariables();

	bool fileIsEmpty(std::fstream& file);
	bool fileIsEmpty(std::ifstream& file);
};

#endif
