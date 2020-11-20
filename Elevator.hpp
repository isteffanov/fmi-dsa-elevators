#pragma once
#include <iostream>
#include "Command.hpp"

class Elevator
{
	size_t passengerCap;
	size_t floorCap;
	size_t curFloor;
	size_t curPassengers;

public:
	Elevator(size_t pCap = 4, size_t fCap = 4);

	void execute(const Command& command);
};

