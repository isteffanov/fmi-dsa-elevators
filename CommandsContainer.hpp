#pragma once
#include <list>
#include <forward_list>
#include "Command.hpp"

class CommandsContainer
{
	std::forward_list<Command*> commands;

public:
	void add(Command* command);

	void print() const;
};