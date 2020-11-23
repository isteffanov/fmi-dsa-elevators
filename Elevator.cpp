#include "Elevator.hpp"

Elevator::Elevator(char type, size_t pCap, size_t fCap)
	:f_type(type), passengerCap(pCap), floorCap(fCap), curFloor(1), curPassengers(0){}



void Elevator::addRequests(std::list<Request>& other)
{
	for (Request& r : other)
		allRequests.push_front(r);
}

size_t Elevator::floor() const
{
	return curFloor;
}

size_t Elevator::passengers() const
{
	return curPassengers;
}

const std::list<Request>& Elevator::requests() const
{
	return allRequests;
}

void Elevator::setFloor(size_t floor)
{
	curFloor = floor;
}

size_t Elevator::time(size_t time, size_t floor)
{
	return time + 5*mod(floor - curFloor);
}

size_t Elevator::mod(int n)
{
	return (n >= 0 ? n : -n);
}

