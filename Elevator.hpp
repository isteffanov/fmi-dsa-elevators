#pragma once
#include <iostream>
#include "Command.hpp"

class Elevator
{
	enum State {
		UP,
		DOWN,
		IDLE = -1
	};
	size_t passengerCap;
	size_t floorCap;
	size_t curFloor;
	size_t curPassengers;

public:
	Elevator(size_t pCap = 4, size_t fCap = 4);

	//size_t arrival(const Command& command);
	size_t arrivalCall(const CallCommand& call);
	//size_t arrivalGo(const GoCommand& go);
	void execute(const Command& command);

	size_t mod(int n);
};

