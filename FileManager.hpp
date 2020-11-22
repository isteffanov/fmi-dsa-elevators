#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "Command.hpp"
#include "Request.hpp"

class FileManager
{
	struct Meta {
		size_t floorsNum;
		size_t largeCap;
		size_t smallCap;
		size_t commandsNum;

		Meta(size_t floors = 0, size_t large = 0, size_t small = 0 ,  size_t commands = 0)
			:floorsNum(floors), largeCap(large), smallCap(small), commandsNum(commands) {}

		friend std::ifstream& operator>>(std::ifstream& stream, Meta& meta) {
			if (stream.is_open()) {
				size_t floors, large, small, commands;
				stream >> floors >> large>> small >> commands;

				meta = Meta(floors, large, small, commands);
			}

			return stream;
		}
	};

	std::ifstream stream;
	Meta meta;
	
	Call getCall();
	Go getGo();
	
public:
	FileManager(std::string file = "");

	const std::queue<Request> commands();

	size_t floors()	  const;
	size_t large()	  const;
	size_t small()	  const;
	size_t commands_num() const;
};

