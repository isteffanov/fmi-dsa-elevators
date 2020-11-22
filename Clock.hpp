#pragma once
#include "Command.hpp"

class Clock
{
	size_t time;

public:
	Clock();

	size_t whats_the_time() const;
};

