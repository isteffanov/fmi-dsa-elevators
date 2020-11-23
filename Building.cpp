#include "Building.hpp"

Building::Building(size_t largeCap, size_t smallCap, size_t floorCap)
	:large('L', largeCap, floorCap), small('S', smallCap, floorCap), people(floorCap) {}

void Building::execute()
{
	std::string dir;
	for (const Request& request : large.requests()) {
		dir = (request.call().floor() - large.floor() >= 0 ? "UP" : "DOWN");
		request.call().print('L', dir);
		large.setFloor(request.call().floor());

		dir = (request.go().floor() - large.floor() >= 0 ? "UP" : "DOWN");
		request.go().print('L', dir);
		large.setFloor(request.go().floor());
	}

	for (const Request& request : small.requests()) {
		dir = (request.call().floor() - small.floor() >= 0 ? "UP" : "DOWN");
		request.call().print('S', dir);
		large.setFloor(request.call().floor());

		dir = (request.go().floor() - small.floor() >= 0 ? "UP" : "DOWN");
		request.go().print('S', dir);
		large.setFloor(request.go().floor());
	}
}

bool Building::interfere(const Request& c1, const Request& c2)
{
	size_t time1 = c1.call().time();
	size_t startFloor1 = c1.call().floor();

	size_t time2 = c2.call().time();
	size_t startFloor2 = c2.call().floor();

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
