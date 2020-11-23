#include "Building.hpp"

Building::Building(size_t largeCap, size_t smallCap, size_t floorCap)
	:large(largeCap, floorCap), small(smallCap, floorCap), people(floorCap) {}

bool Building::interfere(const Command& c1, const Command& c2)
{
	size_t time1 = c1.time();
	size_t startFloor1 = c1.floor();

	size_t time2 = c2.time();
	size_t startFloor2 = c2.floor();

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
		std::cout << " D: " << dir;
		calls.pop();
		size_t arrival = arrival()
		if(gos.top().time())
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
