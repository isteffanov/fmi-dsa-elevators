#include "Simulation.hpp"

void Simulation::begin()
{
	init();

	std::queue<Command> commandsQueue = manager.commands();
	while (!commandsQueue.empty()) {
		commandsQueue.front().print();
		commandsQueue.pop();
	}
}

void Simulation::init()
{
	manager = FileManager(file());

	size_t floorsNum = manager.floors();
	size_t largeCap = manager.large();
	size_t smallCap = manager.small();

	building = Building(largeCap, smallCap, floorsNum);
}

Simulation::Simulation() {}

std::string Simulation::file()
{
	std::string filename;
	std::cout << "Enter a filepath: ";
	std::cin >> filename;
	return filename;
}


