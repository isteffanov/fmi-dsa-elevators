#include "FileManager.hpp"s

FileManager::FileManager(std::string file)
{
	stream.open(file.c_str());
	if (file != "" && !stream.is_open()) 
		throw std::exception("Could not open file");

	stream >> meta;
}

size_t FileManager::floors() const
{
	return meta.floorsNum;
}

size_t FileManager::large() const
{
	return meta.largeCap;
}

size_t FileManager::small() const
{
	return meta.smallCap;
}

size_t FileManager::commands() const
{
	return meta.commandsNum;
}

