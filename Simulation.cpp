#include "Simulation.hpp"

Simulation::Simulation() {}

void Simulation::begin()
{
	init();

	
	std::queue<Request> requestQueue = manager.commands();
	while (!requestQueue.empty()) {

		std::list<Request> sequence;
		Request first = requestQueue.front();
		//requestQueue.pop();

		do {
			sequence.push_back(requestQueue.front());
			requestQueue.pop();
		} while (!requestQueue.empty() && building.interfere(first, requestQueue.front()));

		building.chooseElevator(sequence.front()).addRequests(sequence);
	}

	building.execute();
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


