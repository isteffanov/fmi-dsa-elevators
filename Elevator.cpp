#include "Elevator.hpp"

Elevator::Elevator(size_t pCap, size_t fCap)
	:passengerCap(pCap), floorCap(fCap), curFloor(1), curPassengers(0){}

size_t Elevator::arrivalCall(const CallCommand& call)
{
	return call.time() + 5*mod(curFloor - call.floor());
}

void Elevator::execute(const Command& command)
{
	std::cout << "opa";
}

size_t Elevator::mod(int n)
{
	return (n >= 0 ? n : -n);
}
