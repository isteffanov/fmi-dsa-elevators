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

};

