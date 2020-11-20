#include "Command.hpp"

CallCommand::CallCommand(std::string dir, size_t floor, size_t time)
	:dirToGo(dir), floorCalled(floor), timeCalled(time){}

std::string CallCommand::dir() const
{
	return dirToGo;
}

size_t CallCommand::floor() const
{
	return floorCalled;
}

size_t CallCommand::time() const
{
	return timeCalled;
}

GoCommand::GoCommand(size_t floor, size_t time)
	: floorToGo(floor), timeCalled(time){}

size_t GoCommand::floor() const
{
	return floorToGo;
}

size_t GoCommand::time() const
{
	return timeCalled;
}

Command::Command(CallCommand call, GoCommand go)
	:callComm(call), goComm(go){}

const CallCommand& Command::call() const
{
	return callComm;
}

const GoCommand& Command::go() const
{
	return goComm;
}

void Command::print() const
{
	std::cout << "F: " << goComm.floor() << " T: " << callComm.time() << std::endl;
}
