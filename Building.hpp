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

	Building(size_t largeCap, size_t smallCap);

};

