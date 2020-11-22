#pragma once
#include "Clock.hpp"
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

	bool interfere(const Command& c1, const Command& c2);
	void execute(const Command& command);
	size_t arrival(size_t time, size_t start, size_t dest);
	size_t mod(int n);
};


