#pragma once
#include<list>
#include "Clock.hpp"
#include "Elevator.hpp"
#include "WaitingPeople.hpp"
#include "Request.hpp"

class Building
{
	Clock clock;
	Elevator large;
	Elevator small;
	WaitingPeople people;

public:
	Building(size_t largeCap = 0, size_t smallCap = 0, size_t floorCap = 0);

	void execute();
	bool interfere(const Request& c1, const Request& c2);
	Elevator& chooseElevator(const Request& request);
	size_t arrival(size_t time, size_t start, size_t dest);
	size_t mod(int n);
};


