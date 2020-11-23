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

