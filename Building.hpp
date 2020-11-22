#pragma once
#include<list>
#include<queue>
#include<stack>
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

	bool interfere(const Request& c1, const Request& c2);
	void execute(const std::list<Request>& sequence);
	size_t arrival(size_t time, size_t start, size_t dest);
	size_t mod(int n);
};


