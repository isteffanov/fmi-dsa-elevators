#include "Request.hpp"

Request::Request(const Call& call, const Go& go)
	:f_call(call), f_go(go) {}

const Call& Request::call() const
{
	return f_call;
}

const Go& Request::go() const
{
	return f_go;
}
