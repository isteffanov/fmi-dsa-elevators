#include "Command.hpp"

Command::Command(size_t floor, size_t time)
	:f_floor(floor), f_time(time) {}

/* CALL class */

Call::Call(std::string dir, size_t floor, size_t time)
	:f_dir(dir), Command(floor, time){}

std::string Call::dir() const
{
	return f_dir;
}

size_t Call::floor() const
{
	return f_floor;
}

size_t Call::time() const
{
	return f_time;
}

void Call::print() const
{
	std::cout << "Call D: " << dir << " F: " << floor << " T: " << time << std::endl;
}

/* GO class */

Go::Go(size_t floor, size_t time)
	: Command(floor, time){}

size_t Go::floor() const
{
	return f_floor;
}

size_t Go::time() const
{
	return f_time;
}

void Go::print() const
{
	std::cout << "Go F: " << floor << " T: " << time << std::endl;
}




