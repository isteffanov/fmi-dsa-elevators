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

void Command::print() const
{
	std::cout << "F: " << f_floor << " T: " << f_time << std::endl;
}

/* CALL methods */

Call::Call(std::string dir, size_t floor, size_t time)
	:f_dir(dir), Command(floor, time){}

std::string Call::dir() const
{
	return f_dir;
}

bool Call::intefere(const Call& other)
{
	size_t arrival = f_time + std::abs((int)f_floor - (int)other.f_floor);

	if (f_dir != other.f_dir) return false;
	if (arrival > other.f_time) return false;

	return true;
}

/* GO methods*/

Go::Go(size_t floor, size_t time)
	: Command(floor, time) {}

bool Go::intefere(const Go& other)
{
	return false;
}


