#include "Request.hpp"

Request::Request(Call call, Go go)
	:f_call(call), f_go(go), callDone(false), goDone(false) {}

const Call& Request::call() const
{
	return f_call;
}

const Go& Request::go() const
{
	return f_go;
}

Stop::Stop(char elevator, size_t time, size_t floor, std::string dir)
	: f_elevator(elevator), f_time(time), f_floor(floor), f_dir(dir){}

const char& Stop::elevator() const
{
	return f_elevator;
}

const size_t& Stop::time() const
{
	return f_time;
}

const size_t& Stop::floor() const
{
	return f_floor;
}

const std::string& Stop::dir() const
{
	return f_dir;
}
