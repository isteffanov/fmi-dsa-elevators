#pragma once
#include <forward_list>
#include "CommandsContainer.hpp"
#include "FileManager.hpp"
#include "Building.hpp"

class Simulation
{
	FileManager manager;
	Building building;

	std::string file();
	void init();
public:
	Simulation();

	void begin();
};

