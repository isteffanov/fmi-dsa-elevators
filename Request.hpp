#pragma once
#include "Command.hpp"

class Request
{
	Call f_call;
	Go	 f_go;

public:
	Request(const Call& call, const Go& go);

	const Call& call() const;
	const Go& go() const;
};

