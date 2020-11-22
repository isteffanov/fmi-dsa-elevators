#include "CommandsContainer.hpp"

void CommandsContainer::add(Command* command)
{

	commands.push_front(command);
}


void CommandsContainer::print() const
{
	for (const Command* command : commands)
		command->print();
}

