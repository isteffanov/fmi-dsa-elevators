#pragma once
#include <vector>

struct WaitingPeople {
private:
	std::vector<size_t> people;

public:
	WaitingPeople(size_t floors);
};

