#pragma once
#include <list>
#include <string>
#include "Request.hpp"

class Elevator
{
	char f_type;
	size_t passengerCap;
	size_t floorCap;
	size_t curFloor;
	size_t curPassengers;

	std::list<Request> allRequests;

public:
	Elevator(char = 'L', size_t pCap = 4, size_t fCap = 4);
	void addRequests(std::list<Request>& other);

	size_t floor()		const;
	size_t passengers() const;
	std::list<Stop> stops();
	void addSorted(std::list<Stop> stops, const Request& toAdd) const;
	const std::list<Request>& requests() const;


	void execute(const Request& request);
	size_t time(size_t time, size_t floor);
	size_t mod(int n);
};

