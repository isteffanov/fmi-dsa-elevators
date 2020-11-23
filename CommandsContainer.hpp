#pragma once
#include <list>
#include <forward_list>
#include "Command.hpp"

class CommandsContainer
{
	std::forward_list<Command*> commands;

public:
	void add(Command* command);
	const std::forward_list<Command*>& list() const;

	bool empty() const;
	Command* front_ptr() const;
	const Command& front() const;
	void pop();

	void print() const;
};