#include "Elevator.hpp"

Elevator::Elevator(size_t pCap, size_t fCap)
	:passengerCap(pCap), floorCap(fCap), curFloor(1), curPassengers(0){}

void Elevator::execute(const Command& command)
{
	std::cout << "opa";
}
