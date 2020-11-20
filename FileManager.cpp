#include "FileManager.hpp"

FileManager::FileManager(std::string file)
{
	stream.open(file.c_str());
	if (file != "" && !stream.is_open()) 
		throw std::exception("Could not open file");

	stream >> meta;
}

CallCommand FileManager::getCall()
{
	std::string type, dir;
	size_t floor, time;
	stream >> type >> dir >> floor >> time;

	if (type == "go") throw std::exception("Invalid command type!");
	else if (type != "call") throw std::exception("Invalid command!");
	
	else return CallCommand(dir, floor, time);
}
GoCommand FileManager::getGo()
{
	std::string type;
	size_t floor, time;
	stream >> type >> floor >> time;

	if (type == "call") throw std::exception("Invalid command type!");
	else if (type != "go") throw std::exception("Invalid command!");

	else return GoCommand(floor, time);
}

const std::queue<Command> FileManager::commands()
{
	std::queue<Command> commandsQueue;
	try {
		for (int i = 0; i < meta.commandsNum; ++i) {
			CallCommand call = getCall();
			GoCommand   go = getGo();

			commandsQueue.push(Command(call, go));
		}
		stream.close();

		return commandsQueue;
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

