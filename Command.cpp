#include "Command.hpp"

Command::Command(size_t floor, size_t time)
	:f_floor(floor), f_time(time) {}

size_t Command::floor() const
{
	return f_floor;
}

size_t Command::time() const
{
	return f_time;
}

void Command::print(char elevator, std::string dir, size_t timeAdded) const
{
	std::cout << "A: " << elevator << " D: " << dir  << " F: " << f_floor << " T: " << f_time + timeAdded<< std::endl;
}

/* CALL methods */

Call::Call(std::string dir, size_t floor, size_t time)
	:f_dir(dir), Command(floor, time){}

std::string Call::dir() const
{
	return f_dir;
}

/* GO methods*/

Go::Go(size_t floor, size_t time)
	: Command(floor, time) {}



