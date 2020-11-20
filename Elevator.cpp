#include "Elevator.hpp"

Elevator::Elevator(size_t cap)
	:maxCapacity(cap), curFloor(1), curPassengers(0){}

void Elevator::execute(const Command& command)
{
	std::cout << "opa";
}
