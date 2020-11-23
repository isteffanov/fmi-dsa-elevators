#include "CommandsContainer.hpp"

void CommandsContainer::add(Command* command)
{
	commands.push_front(command);
}

const std::forward_list<Command*>& CommandsContainer::list() const
{
	return commands;
}

bool CommandsContainer::empty() const
{
	return commands.empty();
}

Command* CommandsContainer::front_ptr() const
{
	return commands.front();
}

const Command& CommandsContainer::front() const
{
	return *(commands.front());
}

void CommandsContainer::pop()
{
	commands.pop_front();
}


void CommandsContainer::print() const
{
	for (const Command* command : commands)
		command->print();
}

