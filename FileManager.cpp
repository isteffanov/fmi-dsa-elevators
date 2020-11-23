#include "FileManager.hpp"

FileManager::FileManager(std::string file)
{
	stream.open(file.c_str());
	if (file != "" && !stream.is_open()) 
		throw std::exception("Could not open file");

	stream >> meta;
}

Call FileManager::getCall()
{
	std::string type, dir;
	size_t floor, time;
	stream >> type >> dir >> floor >> time;

	if (type == "go") throw std::exception("Invalid command type!");
	else if (type != "call") throw std::exception("Invalid command!");
	
	else return Call(dir, floor, time);
}
Go FileManager::getGo()
{
	std::string type;
	size_t floor, time;
	stream >> type >> floor >> time;

	if (type == "call") throw std::exception("Invalid command type!");
	else if (type != "go") throw std::exception("Invalid command!");

	else return Go(floor, time);
}

const CommandsContainer FileManager::commands()
{
	CommandsContainer container;
	try {
		for (int i = 0; i < meta.commandsNum; ++i) {
			Call call = getCall();
			Go   go = getGo();

			container.add(&call);
			container.add(&go);
		}
		stream.close();

		return container;
	}
	catch (...) {
		throw;
	}
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

size_t FileManager::commands_num() const
{
	return meta.commandsNum;
}

