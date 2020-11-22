#include "Simulation.hpp"

void Simulation::begin()
{
	try {
		init();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	

	std::forward_list<Command> commandsList;
	std::queue<Command> commandsQueue = manager.commands();

	while (!commandsQueue.empty()) {

		do {
			commandsList.push(commandsQueue.front());
			commandsQueue.pop();
		} while (!commandsQueue.empty() && building.interfere(commandsList.front(), commandsQueue.front()));

		building.execute(commandsList);
	}
}

void Simulation::init()
{
	try {
		manager = FileManager(file());

		size_t floorsNum = manager.floors();
		size_t largeCap = manager.large();
		size_t smallCap = manager.small();

		building = Building(largeCap, smallCap, floorsNum);
	}
	catch (...) {
		throw;
	}
	
}

Simulation::Simulation() {}

std::string Simulation::file()
{
	std::string filename;
	std::cout << "Enter a filepath: ";
	std::cin >> filename;
	return filename;
}


