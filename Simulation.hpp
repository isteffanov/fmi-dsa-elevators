#pragma once
#include "FileManager.hpp"
#include "Building.hpp"

class Simulation
{
	FileManager manager;
	Building building;

public:
	void begin();
};

