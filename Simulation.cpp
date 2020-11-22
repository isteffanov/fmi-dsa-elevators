#include "Simulation.hpp"

Simulation::Simulation() {}

void Simulation::begin()
{
	init();

	std::stack<Command> commandsStack;
	std::queue<Command> commandsQueue = manager.commands();
	while (!commandsQueue.empty()) {
		do {
			commandsStack.push(commandsQueue.front());
			commandsQueue.pop();
		} while (!commandsQueue.empty() && building.interfere(commandsStack.top(), commandsQueue.front()));

		while (!commandsStack.empty()) {
			building.execute(commandsStack.top());
			commandsStack.pop();
		}
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


std::string Simulation::file()
{
	std::string filename;
	std::cout << "Enter a filepath: ";
	std::cin >> filename;
	return filename;
}


