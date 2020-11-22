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
	virtual ~Command() {}

	virtual size_t	floor() const = 0;
	virtual size_t	time()  const = 0;
	virtual void	print() const = 0;

};

class Call : public Command
{
	std::string f_dir;

public:
	Call(std::string dir, size_t floor, size_t time);

	std::string dir() const;
	virtual size_t	floor() const;
	virtual size_t	time()  const;
	virtual void	print() const;
};

class Go : public Command
{

public:
	Go(size_t floor, size_t time);

	virtual size_t	floor() const;
	virtual size_t	time()  const;
	virtual void	print() const;
};




