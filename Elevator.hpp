#pragma once
#include <iostream>
#include "Command.hpp"

class Elevator
{
	size_t maxCapacity;
	size_t curFloor;
	size_t curPassengers;

public:
	Elevator(size_t cap = 4);

	void execute(const Command& command);
};

