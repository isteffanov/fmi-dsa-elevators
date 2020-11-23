#pragma once
#include "Command.hpp"

class Request
{
	Call f_call;
	Go	 f_go;
	bool callDone;
	bool goDone;

public:
	Request(Call call, Go go);

	const Call& call() const;
	const Go& go() const;
};

class Stop 
{
	char f_elevator;
	size_t f_time;
	size_t f_floor;
	std::string f_dir;

public:
	Stop(char elevator, size_t time, size_t floor, std::string dir);

	const char&			elevator()	const;
	const size_t&		time()		const;
	const size_t&		floor()		const;
	const std::string&	dir()		const;
};

