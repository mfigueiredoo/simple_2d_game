#include "FileManager.h"

FileManager::FileManager()
{
	this->initVariables();
}

FileManager::FileManager(std::string _pathName)
{
	this->initVariables();
	this->fileName = _pathName;
}

FileManager::~FileManager()
{
}

void FileManager::initVariables()
{
	this->fileName = "";
}

bool FileManager::fileIsEmpty(std::fstream& file)
{
	return file.peek() == std::fstream::traits_type::eof();
}

bool FileManager::fileIsEmpty(std::ifstream& file)
{
	return file.peek() == std::ifstream::traits_type::eof();
}


