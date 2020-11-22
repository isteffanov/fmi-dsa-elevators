#include "Building.hpp"

Building::Building(size_t largeCap, size_t smallCap, size_t floorCap)
	:large(largeCap, floorCap), small(smallCap, floorCap), people(floorCap) {}

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

void Building::execute(const std::list<Request>& sequence)
{
	std::queue<Call> calls;
	std::stack<Go> gos;
	for (const Request& request : sequence) {
		calls.push(request.call());
		gos.push(request.go());
	}

	/* PASS TO CHOSEN ELEVATOR */
	std::string dir = calls.front().dir();

	while (!calls.empty()) {
		calls.front().print();
		std::cout << " D: " dir;
	}
}

size_t Building::arrival(size_t time, size_t start, size_t dest)
{
	return time + 5*mod(start - dest);
}

size_t Building::mod(int n)
{
	return (n >= 0 ? n : -n);
}
