#pragma once

#include <iostream>
#include <fstream>

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class FileManager
{
private:

public:

	std::string fileName;

	FileManager();
	FileManager(std::string maps_pathName);
	~FileManager();

	void initVariables();

	bool fileIsEmpty(std::fstream& file);
	bool fileIsEmpty(std::ifstream& file);
};

#endif
