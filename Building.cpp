#include "Building.hpp"

Building::Building(size_t largeCap, size_t smallCap, size_t floorCap)
	:large('L', largeCap, floorCap), small('S', smallCap, floorCap), people(floorCap) {}

void Building::execute()
{
	std::list<Request> requestsLarge = large.requests();
	std::list<Request> requestsSmall = small.requests();

	for (const Request& requestLarge : requestsLarge) {
		for (const Request& requestSmall : requestsSmall) {
			
			size_t floorCallLarge	= requestLarge.call().floor();
			size_t timeCallLarge	= requestLarge.call().time();
			size_t floorCallSmall	= requestSmall.call().floor();
			size_t timeCallSmall	= requestSmall.call().time();

			if (large.time(timeCallLarge, floorCallLarge) < small.time(timeCallSmall, floorCallSmall))
				small.execute(requestSmall);

			else large.execute(requestLarge);

		}
	}
}

bool Building::interfere(const Request& c1, const Request& c2)
{
	size_t time1 = c1.call().time();
	size_t startFloor1 = c1.call().floor();

	size_t time2 = c2.call().time();
	size_t startFloor2 = c2.call().floor();

	//	TODO double check those statements
	if (c1.call().dir() != c2.call().dir()) return false;
	if (arrival(time1, startFloor1, startFloor2) > time2) return false;
	
	return true;
}

Elevator& Building::chooseElevator(const Request& request) 
{
	size_t floorToGo = request.call().floor();
	//TODO busyness
	if		(mod(small.floor() - floorToGo) > mod(large.floor() - floorToGo)) return small;
	else  return large;
}

size_t Building::arrival(size_t time, size_t start, size_t dest)
{
	return time + 5*mod(start - dest);
}

size_t Building::mod(int n)
{
	return (n >= 0 ? n : -n);
}
