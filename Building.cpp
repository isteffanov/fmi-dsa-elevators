#include "Building.hpp"

Building::Building(size_t largeCap, size_t smallCap, size_t floorCap)
	:large(largeCap, floorCap), small(smallCap, floorCap), people(floorCap) {}

bool Building::interfere(const Command c1, const Command c2)
{
	size_t time1 = c1.call().time();
	size_t start1 = c1.call().floor();
	size_t dest1 = c1.go().floor();

	size_t time2 = c2.call().time();
	size_t start2 = c2.call().floor();

	if (c1.call().dir() != c2.call().dir()) return false; //different dirs do not interfere
	if (arrival(time1, start1, start2) < time2) return false; //missed the cabin

	return true;
}

size_t Building::arrival(size_t time, size_t startFloor, size_t destFloor) const
{
	return time + 5*std::abs((int)destFloor - (int)startFloor); // it takes 5 seconds to travel one floor
}

void Building::execute(const std::forward_list<Command>& commands)
{

}

Elevator& Building::chooseElevator(const Command& command)
{
	
	return large;
}
