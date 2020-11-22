#pragma once
#include <iostream>
#include <string>

class Command
{
protected:
	size_t f_floor;
	size_t f_time;

public:
	Command(size_t floor, size_t time);

	size_t floor() const;
	size_t time()  const;
	void print() const;
};


struct Call : public Command{
private:
	std::string f_dir;

public:
	Call(std::string dir = "", size_t floor = 0, size_t time = 0);

	std::string dir() const;
};

struct Go : public Command{

public:
	Go(size_t floor = 0, size_t time = 0);

};
