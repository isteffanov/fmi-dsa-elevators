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


