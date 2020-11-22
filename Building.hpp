#pragma once
#include <forward_list>
#include "Clock.hpp"
#include "Command.hpp"
#include "Elevator.hpp"
#include "WaitingPeople.hpp"

class Building
{
	Clock clock;
	Elevator large;
	Elevator small;
	WaitingPeople people;

public:
	Building(size_t largeCap = 0, size_t smallCap = 0, size_t floorCap = 0);

	bool interfere(const Command c1, const Command c2);
	size_t arrival(size_t time, size_t startFloor, size_t destFloor) const;

	void execute(const std::forward_list<Command>& commands);

	Elevator& chooseElevator(const Command& command);

};

