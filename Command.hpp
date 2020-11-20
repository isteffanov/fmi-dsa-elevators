#pragma once
#include <iostream>
#include <string>

struct CallCommand {
private:
	std::string dirToGo;
	size_t floorCalled;
	size_t timeCalled;

public:
	CallCommand(std::string dir = "", size_t floor = 0, size_t time = 0);

	std::string dir() const;
	size_t floor() const;
	size_t time() const;
};

struct GoCommand {
private:
	size_t floorToGo;
	size_t timeCalled;

public:
	GoCommand(size_t floor = 0, size_t time = 0);

	size_t floor() const;
	size_t time() const;
};

class Command
{
	CallCommand callComm;
	GoCommand goComm;

public:
	Command(CallCommand call = CallCommand(), GoCommand go = GoCommand());

	const CallCommand& call() const;
	const GoCommand&   go()   const;
	void print() const;
};

